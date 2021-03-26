#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

struct StronglyConnectedComponent {
        int n;
        vector<bool> used;
        vector<int> order, cmp;
        vector<vector<int>> g, rg;
        StronglyConnectedComponent(int x) {
                n = x;
                g.resize(x);
                rg.resize(x);
                used.resize(x);
                cmp.resize(x);
        }
        void add_edge(int from, int to) {
                g[from].push_back(to);
                rg[to].push_back(from);
        }
        void dfs(int u) {
                used[u] = true;
                for (auto v : g[u]) if (!used[v]) {
                        dfs(v);
                }
                order.push_back(u);
        }
        void rdfs(int u, int k) {
                used[u] = true;
                cmp[u] = k;
                for (auto v : rg[u]) if (!used[v]) {
                        rdfs(v, k);
                }
        }
        int init() {
                used.assign(n, false);
                for (int u = 0; u < n; u ++) {
                        if (!used[u]) {
                                dfs(u);
                        }
                }
                used.assign(n, false);
                int k = 0;
                for (int i = order.size() - 1; i >= 0; i --) {
                        if (!used[order[i]]) {
                                rdfs(order[i], k ++);
                        }
                }
                return k;
        }
};

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n), rg(n);
        StronglyConnectedComponent scc(n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                rg[b].push_back(a);
                scc.add_edge(a, b);
        }
        scc.init();
        set<int> st;
        rep(i, n) {
                if (st.count(scc.cmp[i])) {
                        cout << -1 << '\n';
                        return;
                }
                st.insert(scc.cmp[i]);
        }

        string ans = string(n, '*');
        rep(i, n) {
                if (ans[i] == 'E') {
                        break;
                }
                if (g[i].size() > 0 && rg[i].size() > 0) {
                        ans[i] = 'E';
                        break;
                }
                for (auto j : g[i]) {
                        ans[j] = 'E';
                }
                for (auto j : rg[i]) {
                        ans[j] = 'E';
                }
                ans[i] = 'A';
        }
        int c = 0;
        rep(i, n) {
                if (ans[i] == 'E') {
                        for (int j = i + 1; j < n; j ++) {
                                ans[j] = 'E';
                        }
                        break;
                }
                c ++;
        }
        cout << c << '\n';
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
