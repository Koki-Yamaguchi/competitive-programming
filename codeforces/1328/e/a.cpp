#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        vector<int> par(n, 0);
        function<void (int, int)> unko = [&](int u, int prev) {
                for (int v : g[u]) if (v != prev) {
                        par[v] = u;
                        unko(v, u);
                }
        };
        unko(0, -1);
        vector<int> need(m);
        vector<bool> ans(m);
        vector<vector<int>> qs(n);
        rep(i, m) {
                int c;
                cin >> c;
                need[i] = c;
                rep(j, c) {
                        int u;
                        cin >> u;
                        u --;
                        qs[par[u]].push_back(i);
                }
        }
        vector<int> cnt(m);
        function<void (int, int)> dfs = [&](int u, int prev) {
                for (int x : qs[u]) {
                        cnt[x] ++;
                        if (cnt[x] == need[x]) {
                                ans[x] = true;
                        }
                }
                for (int v : g[u]) if (v != prev) {
                        dfs(v, u);
                }
                for (int x : qs[u]) {
                        cnt[x] --;
                }
        };
        dfs(0, -1);
        rep(i, m) {
                cout << (ans[i] ? "YES" : "NO") << '\n';
        }
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
