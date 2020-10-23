#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        vector<int> val, sz(n);
        function<void (int, int, int)> dfs = [&](int u, int prev, int dep) {
                sz[u] = 1;
                for (int v : g[u]) if (v != prev) {
                        dfs(v, u, dep + 1);
                        sz[u] += sz[v];
                }
                val.push_back(dep - sz[u] + 1);
        };
        dfs(0, -1, 0);
        sort(all(val));
        reverse(all(val));
        ll ans = 0;
        rep(i, k) {
                ans += val[i];
        }
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
