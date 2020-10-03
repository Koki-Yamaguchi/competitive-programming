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
        vector<pair<int, int>> es, okes;
        StronglyConnectedComponent scc(n);
        rep(i, m) {
                int t, a, b;
                cin >> t >> a >> b;
                a --, b --;
                if (t == 0) {
                        es.emplace_back(a, b);
                } else {
                        scc.add_edge(a, b);
                        okes.emplace_back(a, b);
                }
        }
        scc.init();
        cerr << "scc.cmp" << endl;
        rep(i, n) cerr << scc.cmp[i] << " "; cerr << endl;
        set<int> app;
        rep(i, n) {
                if (app.count(scc.cmp[i])) {
                        cout << "NO\n";
                        return;
                }
                app.insert(scc.cmp[i]);
        }
        for (pair<int, int> e : es) {
                if (scc.cmp[e.first] < scc.cmp[e.second]) {
                        okes.emplace_back(e.first, e.second);
                } else {
                        okes.emplace_back(e.second, e.first);
                }
        }
        assert(okes.size() == m);
        cout << "YES\n";
        rep(i, okes.size()) {
                cout << okes[i].first + 1 << " " << okes[i].second + 1 << '\n';
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
