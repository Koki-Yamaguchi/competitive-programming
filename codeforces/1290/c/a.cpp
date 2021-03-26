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
        string s;
        cin >> s;
        vector<vector<int>> lights(n);
        rep(i, m) {
                int sz;
                cin >> sz;
                rep(j, sz) {
                        int x;
                        cin >> x;
                        x --;
                        lights[x].push_back(i);
                }
        }
        UnionFind uf(m);

        // access by root
        vector<vector<int>> vs(m);
        rep(i, m) { vs[i].push_back(i); }
        vector<bool> rev(m, false), det(m, false); // if the color is determined or not
        vector<vector<int>> num(m);
        rep(i, m) { num[i].push_back({1, 0}); } // num[i][0 ^ rev[i]] ... number of off, num[i][1 ^ rev[i]] ... on

        // access by vertice
        vector<int> color(m, 0); // color[i] ^ rev[i] ... 0 off, 1 on

        vector<vector<pair<int, bool>>> g(m); // (to, change or not)
        int ans = 0;
        rep(i, n) {
                bool need_change = (s[i] == '0');
                if (lights[i].size() == 1) {
                        int u = lights[i][0];
                        int root = uf.find(u);
                        if (need_change && ((not rev[root] && color[u] == 1) || (rev[root] && color[u] == 0))) {
                                // nothing
                        } else if (not need_change && ((rev[root] && color[u] == 1) || (not rev[root] && color[u] == 0))) {
                                // nothing
                        } else {
                                assert(not det[root]);
                                det[root] = true;
                                rev[root] = not rev[root];
                                if (rev[root]) {
                                        ans += num[root].first - num[root].second;
                                } else {
                                        ans += num[root].second - num[root].first;
                                }
                        }
                } else if (lights[i].size() == 2) {
                        int u = lights[i][0];
                        int v = lights[i][1];
                        int ur = uf.find(u);
                        int vr = uf.find(v);
                        if (vs[ur].size() > vs[vr].size()) {
                                swap(u, v);
                                swap(ur, vr);
                        }
                        bool uc = color[u] ^ rev[ur];
                        bool vc = color[v] ^ rev[vr];
                        int uoff = num[ur][0 ^ rev[ur]];
                        int uon = num[ur][1 ^ rev[u]];
                        int voff = num[vr][0 ^ rev[vr]];
                        int von = num[vr][1 ^ rev[vr]];

                        if (det[ur] && det[vr]) {
                                if ((rev[ur] && not rev[vr]) || (not rev[ur] && rev[vr])) {
                                        change_color(u, -1);
                                }
                                if (need_change) {
                                        assert(uc != vc);
                                        g[u].emplace_back(v, true);
                                        g[v].emplace_back(u, true);
                                } else {
                                        assert(uc == vc);
                                        g[u].emplace_back(v, false);
                                        g[v].emplace_back(u, false);
                                }
                        } else if (det[ur]) {
                                if (need_change) {
                                        if (uc == vc) {
                                                rev[vr] = not rev[vr];
                                        }
                                } else {
                                }
                                det[vr] = true;
                        } else if (det[vr]) {
                        } else {
                        }

                        // merge anyway
                        for (auto w : vs[ur]) {
                                vs[vr].push_back(w);
                        }
                        vs[ur].clear();
                        uf.parent[ur] = vr;
                } else {
                        assert(false);
                }
                cout << ans << '\n';
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
