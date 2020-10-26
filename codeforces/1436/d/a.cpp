#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int p;
                cin >> p;
                p --;
                g[p].push_back(i + 1);
        }
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<ll> acc(n);
        vector<int> leaves(n);
        ll ans = 0;
        function<void (int)> dfs = [&](int u) {
                acc[u] = a[u];
                for (int v : g[u]) {
                        dfs(v);
                        acc[u] += acc[v];
                        leaves[u] += leaves[v];
                }
                if (g[u].size() == 0) {
                        leaves[u] = 1;
                }
                ans = max(ans, (acc[u] + leaves[u] - 1) / leaves[u]);
        };
        dfs(0);
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
