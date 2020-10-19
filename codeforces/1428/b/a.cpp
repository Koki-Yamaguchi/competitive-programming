#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

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
        string s;
        cin >> s;
        StronglyConnectedComponent scc(n);
        rep(i, n) {
                if (s[i] == '-') {
                        scc.add_edge(i, (i + 1) % n);
                        scc.add_edge((i + 1) % n, i);
                } else if (s[i] == '<') {
                        scc.add_edge((i + 1) % n, i);
                } else {
                        scc.add_edge(i, (i + 1) % n);
                }
        }
        scc.init();
        map<int, int> cnt;
        rep(i, n) {
                cnt[scc.cmp[i]] ++;
        }
        int ans = 0;
        rep(i, n) {
                if (cnt[scc.cmp[i]] > 1) {
                        ans ++;
                }
        }
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
