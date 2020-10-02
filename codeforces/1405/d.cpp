#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

//verified by 'http://codeforces.com/contest/911/problem/F'
vector<int> DiameterPath(const vector<vector<int>> &g) {
        int n = g.size();
        if (n == 1) return vector<int> { 0 };
        //find the farthest point from the start
        auto farthest = [&](int start) {
                vector<int> depth(n);
                function<void (int, int, int)> get_depth = [&](int u, int prev, int d) {
                        depth[u] = d;
                        for (auto v : g[u]) if (v != prev) {
                                get_depth(v, u, d + 1);
                        }
                };
                get_depth(start, -1, 0);
                int maxd = 0;
                int res = 0;
                for (int i = 0; i < n; i ++) {
                        if (depth[i] > maxd) {
                                maxd = depth[i];
                                res = i;
                        }
                }
                return res;
        };
        //get end points
        int s = farthest(0);
        int t = farthest(s);
        //construct a diameter path
        vector<int> diameter_path;
        function<void (int, int, vector<int> &)> construct = [&](int u, int prev, vector<int> &path) {
                if (u == t) {
                        diameter_path = path;
                        return;
                }
                for (auto v : g[u]) if (v != prev) {
                        path.push_back(v);
                        construct(v, u, path);
                        path.pop_back();
                }
        };
        vector<int> tmp;
        tmp.push_back(s);
        construct(s, -1, tmp);
        return diameter_path;
}

void solve() {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        a --, b --;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int u, v;
                cin >> u >> v;
                u --, v --;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        int len = -1;
        function<void (int, int, int)> dfs = [&](int u, int prev, int dep) {
                if (u == b) {
                        len = dep;
                        return;
                }
                for (int v : g[u]) if (v != prev) {
                        dfs(v, u, dep + 1);
                }
        };
        dfs(a, -1, 0);
        if (len <= da) {
                cout << "Alice" << '\n';
                return;
        }

        auto p = DiameterPath(g);
        if (2 * da >= p.size() - 1) {
                cout << "Alice" << '\n';
                return;
        }

        if (2 * da >= db) {
                cout << "Alice" << '\n';
                return;
        }

        cout << "Bob" << '\n';
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
