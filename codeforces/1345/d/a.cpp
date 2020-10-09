#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

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
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        int bl = 0;
        rep(i, h) {
                cin >> s[i];
                rep(j, w) {
                        bl += s[i][j] == '#';
                }
        }
        if (bl == 0) {
                cout << 0 << '\n';
                return;
        }
        rep(i, h) {
                bool f = false, ff = false, ng = false;
                rep(j, w) {
                        if (s[i][j] == '#' && !f) {
                                f = true;
                        }
                        if (s[i][j] == '.' && f) {
                                ff = true;
                        }
                        if (s[i][j] == '#' && ff) {
                                ng = true;
                                break;
                        }
                }
                if (ng) {
                        cout << -1 << '\n';
                        return;
                }
        }
        rep(j, w) {
                bool f = false, ff = false, ng = false;
                rep(i, h) {
                        if (s[i][j] == '#' && !f) {
                                f = true;
                        }
                        if (s[i][j] == '.' && f) {
                                ff = true;
                        }
                        if (s[i][j] == '#' && ff) {
                                ng = true;
                                break;
                        }
                }
                if (ng) {
                        cout << -1 << '\n';
                        return;
                }
        }

        vector<bool> is(h), js(w);
        rep(i, h) {
                bool inc = false;
                rep(j, w) {
                        if (s[i][j] == '#') {
                                inc = true;
                                break;
                        }
                }
                if (!inc) {
                        is[i] = true;
                }
        }
        rep(j, w) {
                bool inc = false;
                rep(i, h) {
                        if (s[i][j] == '#') {
                                inc = true;
                                break;
                        }
                }
                if (!inc) {
                        js[j] = true;
                }
        }
        vector<vector<bool>> sused(h, vector<bool> (w));
        rep(i, h) {
                rep(j, w) {
                        if (s[i][j] == '#') {
                                sused[i][j] = true;
                        }
                        if (is[i] && js[j]) {
                                sused[i][j] = true;
                        }
                }
        }
        rep(i, h) {
                bool inc = false;
                rep(j, w) {
                        if (sused[i][j]) {
                                inc = true;
                                break;
                        }
                }
                if (!inc) {
                        cout << -1 << '\n';
                        return;
                }
        }
        rep(j, w) {
                bool inc = false;
                rep(i, h) {
                        if (sused[i][j]) {
                                inc = true;
                                break;
                        }
                }
                if (!inc) {
                        cout << -1 << '\n';
                        return;
                }
        }

        UnionFind uf(bl);
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        map<pair<int, int>, int> z;
        int k = 0;
        rep(i, h) {
                rep(j, w) {
                        if (s[i][j] == '#') {
                                z[make_pair(i, j)] = k ++;
                        }
                }
        }
        rep(i, h) {
                rep(j, w) {
                        if (s[i][j] == '#') {
                                rep(d, 4) {
                                        int ni = i + dy[d];
                                        int nj = j + dx[d];
                                        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                                        if (s[ni][nj] == '#') {
                                                uf.unite(z[make_pair(i, j)], z[make_pair(ni, nj)]);
                                        }
                                }
                        }
                }
        }
        cout << uf.get() << '\n';
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
