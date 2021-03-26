#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

struct LowLink {
        vector<pair<int, int>> bridge;
        vector<int> articulation, ord, low;
        vector<bool> used;
        vector<vector<int>> g;
        int n, k = 0;
        LowLink(const vector<vector<int>> &g) : g(g) {
                n = g.size();
                ord.resize(n, -1);
                low.resize(n, -1);
                used.resize(n, false);
        }
        void dfs(int u, int prev) {
                used[u] = true;
                ord[u] = k ++;
                low[u] = ord[u];
                bool is_articulation = false;
                int cnt = 0;
                for (auto v : g[u]) if (v != prev) {
                        if (!used[v]) {
                                cnt ++;
                                dfs(v, u);
                                low[u] = min(low[u], low[v]);
                                if (low[v] > ord[u]) {
                                        bridge.emplace_back(min(u, v), max(u, v));
                                } 
                                if (prev != -1 && low[v] >= ord[u]) {
                                        is_articulation = true;
                                }
                        } else {
                                low[u] = min(low[u], ord[v]);
                        }
                }
                if (prev == -1 && cnt > 1) is_articulation = true;
                if (is_articulation) articulation.push_back(u);
        }
};

struct UnionFind {
        int n;
        vector<int> parent, rank, num;
        int find(int x) {
                if (parent[x] == x) return  x;
                return parent[x] = find(parent[x]);
        }
        UnionFind(int n_) {
                n = n_;
                parent.resize(n);
                for (int i = 0; i < n; i ++) parent[i] = i;
                rank.assign(n, 0);
                num.assign(n, 1);
        }
        void unite(int x, int y) {
                if ((x = find(x)) != (y = find(y))) {
                        if (rank[x] < rank[y]) {
                                parent[x] = y;
                                num[y] += num[x];
                        } else {
                                parent[y] = x;
                                if (rank[x] == rank[y]) rank[x] ++;
                                num[x] += num[y];
                        }
                        n --;
                }
        }
        bool same(int x, int y) { return find(x) == find(y); }
        int get() { return n; }
        int get(int x) { return num[find(x)]; }
};

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        UnionFind uf(n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
                uf.unite(a, b);
        }
        if (uf.get() != 1) {
                assert(true);
                assert(true);
                cout << "NO\n";
                return;
        }
        LowLink lowlink(g);
        lowlink.dfs(0, -1);
        auto brs = lowlink.bridge;
        set<pair<int, int>> brss;
        for (auto it : brs) {
                brss.insert(minmax(it.first, it.second));
        }
        vector<bool> used(n), color(n);
        auto dfs = [&](auto self, int u, int prev) -> void {
                bool ex = false;
                for (auto v : g[u]) {
                        ex = ex || color[v];
                }
                if (not ex && u) {
                        color[u] = true;
                }
                vector<int> bre, nbre;
                for (auto v : g[u]) if (v != prev && not used[v]) {
                        if (brss.count(minmax(u, v))) {
                                bre.push_back(v);
                        } else {
                                nbre.push_back(v);
                        }
                }
                for (auto v : bre) if (not used[v]) {
                        used[v] = true;
                        self(self, v, u);
                }
                for (auto v : nbre) if (not used[v]) {
                        used[v] = true;
                        self(self, v, u);
                }
        };
        dfs(dfs, 0, -1);
        vector<int> ans;
        rep(i, n) {
                if (color[i]) {
                        ans.push_back(i + 1);
                }
        }
        cout << "YES\n";
        cout << ans.size() << '\n';
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
