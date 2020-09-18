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
        int n;
        cin >> n;
        vector<long long> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        StronglyConnectedComponent scc(n);
        rep(i, n) {
                int b;
                cin >> b;
                if (b > 0) {
                        b --;
                        scc.add_edge(i, b);
                }
        }
        scc.init();
        long long tot = 0;
        vector<int> ans, later;
        reverse(scc.order.begin(), scc.order.end());
        rep(i, n) {
                int u = scc.order[i];
                if (scc.g[u].size() > 0) {
                        if (a[u] >= 0) {
                                a[scc.g[u][0]] += a[u];
                                ans.push_back(u);
                        } else {
                                later.push_back(u);
                        }
                } else {
                        ans.push_back(u);
                }
                tot += a[u];
        }
        reverse(later.begin(), later.end());
        rep(i, later.size()) {
                ans.push_back(later[i]);
        }
        cout << tot << "\n";
        rep(i, n) {
                cout << ans[i] + 1 << " ";
        }
        cout << "\n";
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t = 1;
        // cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
