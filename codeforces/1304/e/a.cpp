#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p) {
        os << p.first << " " << p.second;
        return os;
}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

struct LowestCommonAncestorTree {
        const int LOGM = 30;
        vector<int> depth;
        vector<vector<int>> parent;
        LowestCommonAncestorTree(int root, const vector<vector<int>> &g) {
                int n = g.size();
                depth.resize(n);
                parent.resize(LOGM);
                for (int i = 0; i < LOGM; i ++) parent[i].resize(n);
                function<void (int, int, int)> dfs = [&](int u, int prev, int d) {
                        parent[0][u] = prev;
                        depth[u] = d;
                        for (auto v : g[u]) if (v != prev) dfs(v, u, d + 1);
                };
                dfs(root, -1, 0);
                for (int k = 0; k < LOGM - 1; k ++) {
                        for (int i = 0; i < n; i ++) {
                                if (parent[k][i] < 0) parent[k + 1][i] = -1;
                                else parent[k + 1][i] = parent[k][parent[k][i]];
                        }
                }
        }
        int lca(int u, int v) { 
                if (depth[u] > depth[v]) swap(u, v);
                for (int k = 0; k < LOGM; k ++) {
                        if ((depth[v] - depth[u]) >> k & 1) { 
                                v = parent[k][v];
                        }
                }
                if (u == v) return u;
                for (int k = LOGM - 1; k >= 0; k --) {
                        if (parent[k][u] != parent[k][v]) {
                                u = parent[k][u];
                                v = parent[k][v];
                        }
                }
                return parent[0][u];
        }
        int dist(int u, int v) {
                return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        }
};

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        LowestCommonAncestorTree tree(0, g);
        int q;
        cin >> q;
        while (q --) {
                int u, v, a, b, k;
                cin >> u >> v >> a >> b >> k;
                u --, v --, a --, b --;
                bool change = abs(tree.depth[u] - tree.depth[v]) % 2 == 0;
                bool need_change = (abs(tree.depth[a] - tree.depth[b]) & 1) ^ (k & 1);
                if (need_change && not change) {
                        cout << "NO\n";
                } else if (need_change) {
                        int d = 1e9;
                        d = min(d, tree.dist(a, u) + 1 + tree.dist(v, b));
                        d = min(d, tree.dist(a, v) + 1 + tree.dist(u, b));
                        if (d <= k) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                } else if (not change) {
                        int d = 1e9;
                        d = min(d, tree.dist(a, u) + 1 + tree.dist(v, b));
                        d = min(d, tree.dist(a, v) + 1 + tree.dist(u, b));
                        d = min(d, tree.dist(a, b));
                        if (d <= k) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                } else {
                        int d = 1e9;
                        d = min(d, tree.dist(a, b));
                        if (d <= k) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                }
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
