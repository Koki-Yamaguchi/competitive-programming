#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i ++) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        int m;
        cin >> m;
        vector<int> p(m);
        rep(i, m) {
                cin >> p[i];
        }
        vector<int> sz(n);
        vector<long long> val;
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                for (int v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        val.push_back((long long) sz[v] * (n - sz[v]));
                }
        };
        dfs(0, -1);
        assert(val.size() == n - 1);
        sort(val.rbegin(), val.rend());
        sort(p.rbegin(), p.rend());
        long long ans = 0;
        if (n - 1 >= m) {
                rep(i, n - 1) {
                        if (i < m) {
                                (ans += (long long) val[i] * p[i]) %= MOD;
                        } else {
                                (ans += (long long) val[i] * 1ll) %= MOD;
                        }
                }
        } else {
                int f = m - (n - 2);
                long long ff = 1;
                rep(i, f) {
                        (ff *= p[i]) %= MOD;
                }
                (ans += val[0] * ff) %= MOD;
                for (int i = f; i < m; i ++) {
                        (ans += (long long) val[i - f + 1] * p[i]) %= MOD;
                }
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
