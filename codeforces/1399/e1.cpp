#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
void solve() {
        int n;
        cin >> n;
        long long s;
        cin >> s;
        vector<vector<pair<int, int>>> g(n);
        rep(i, n - 1) {
                int a, b, c;
                cin >> a >> b >> c;
                a --, b --;
                g[a].emplace_back(b, c);
                g[b].emplace_back(a, c);
        }
        vector<int> leaves(n);
        vector<pair<int, int>> val;
        function<void (int, int)> dfs = [&](int u, int prev) {
                for (pair<int, int> e : g[u]) {
                        int v = e.first;
                        if (v == prev) {
                                continue;
                        }
                        dfs(v, u);
                        leaves[u] += leaves[v];
                        val.emplace_back(e.second, leaves[v]);
                }
                if (u != 0 && g[u].size() == 1) {
                        leaves[u] = 1;
                }
        };
        dfs(0, -1);
        priority_queue<pair<long long, pair<int, int>>> que;
        assert(val.size() == n - 1);
        long long cur = 0;
        rep(i, n - 1) {
                long long v = val[i].first;
                long long c = val[i].second;
                long long dec = ((v + 1) / 2) * c;
                que.emplace(make_pair(dec, make_pair(v, c)));
                cur += v * c;
        }
        int ans = 0;
        while (cur > s) {
                auto p = que.top();
                que.pop();
                cur -= p.first;
                long long v = p.second.first / 2;
                long long c = p.second.second;
                long long dec = ((v + 1) / 2) * c;
                que.emplace(make_pair(dec, make_pair(v, c)));
                ans ++;
        }
        cout << ans << '\n';
}
 
int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
