#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

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
        if (k == 1) {
                cout << n - 1 << '\n';
                return;
        }
        vector<bool> deleted(n);
        vector<bool> is_leave(n);
        function<void (int, int)> dfs0 = [&](int u, int prev) {
                int c = 0;
                for (int v : g[u]) if (v != prev) {
                        dfs0(v, u);
                        if (is_leave[v]) {
                                c ++;
                        }
                }
                if (u != 0 && g[u].size() == 1) {
                        is_leave[u] = true;
                        return;
                }
                int del = (c / k) * k;
                int ch = (u == 0 ? g[u].size() : (int) g[u].size() - 1);
                if (del == ch) {
                        is_leave[u] = true;
                }
                for (int v : g[u]) if (v != prev) {
                        if (del == 0) {
                                break;
                        }
                        if (is_leave[v]) {
                                del --;
                                deleted[v] = true;
                        }
                }
        };
        dfs0(0, -1);
        // assert(!deleted[0]);
        int rest = 0;
        int idx = -1;
        for (int v : g[0]) {
                if (!deleted[v]) {
                        idx = v;
                        rest += !deleted[v];
                }
        }
        function<void (int, int)> dfs1 = [&](int u, int prev) {
                // assert(!deleted[u]);
                int c = 0;
                for (int v : g[u]) if (v != prev) {
                        c += (is_leave[v] && !deleted[v]);
                }
                if (c == k - 1) {
                        assert(!deleted[prev]);
                        deleted[prev] = true;
                        for (int v : g[u]) if (v != prev) {
                                if (is_leave[v] && !deleted[v]) {
                                        deleted[v] = true;
                                }
                        }
                        for (int v : g[u]) if (v != prev) {
                                if (!deleted[v] && !deleted[u]) {
                                        dfs1(v, u);
                                }
                        }
                }
        };
        if (rest == 1) {
                dfs1(idx, 0);
        }
        int ans = 0;
        rep(i, n) {
                ans += deleted[i];
        }
        // assert(ans % k == 0);
        cout << ans / k << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        // t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
