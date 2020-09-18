#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> p(n), h(n); 
        rep(i, n) {
                cin >> p[i];
        }
        rep(i, n) {
                cin >> h[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i ++) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        vector<long long> cnt(n), good(n);
        bool ng = false;
        function<void (int, int)> dfs = [&](int u, int prev) {
                cnt[u] = p[u];
                long long sum = 0;
                for (int v : g[u]) if (v != prev) {
                        dfs(v, u);
                        cnt[u] += cnt[v];
                        sum += good[v];
                }
                if ((cnt[u] % 2 != ((h[u] % 2) + 2) % 2) || (cnt[u] < abs(h[u]))) {
                        ng = true;
                        return;
                }
                long long d = (cnt[u] - h[u]) / 2;
                good[u] = cnt[u] - d;
                if (sum > good[u]) {
                        ng = true;
                        return;
                }
        };
        dfs(0, -1);
        if (ng) {
                cout << "NO\n";
        } else {
                cout << "YES\n";
        }
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
