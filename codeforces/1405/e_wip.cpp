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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        vector<int> d(n, -1);
        rep(i, n) {
                if (a[i] <= i) {
                        d[i] = i - a[i];
                }
        }
        rep(i, n) cerr << d[i] << " "; cerr << endl;
        vector<int> to(n, -1), prev(n, -1);
        rep(i, n) {
                if (d[i] == -1) {
                        continue;
                } else if (d[i] == 0) {
                        to[i] = i;
                } else if (prev[d[i] - 1] != -1) {
                        to[i] = prev[d[i] - 1];
                }
                prev[d[i]] = i;
        }
        set<int> app;
        int ans = 0;
        vector<int> res(n);
        UnionFind uf(n);
        vector<int> acc(n);
        acc[0] = (d[0] == 0 ? uf.get(0) : 0);
        vector<pair<pair<int, int>, int>> v(q);
        rep(i, q) {
                v[i].first = i;
                cin >> v[i].second.first >> v[i].second.second;
                v[i].second.second = n - v[i].second.second;
        }
        sort(v.begin(), v.end(), [&](auto l, auto r) {
                return l.second.second < r.second.second;
        });
        int cur = 0;
        rep(i, n) {
                int idx = v[i].first;
                int l = v[i].second.first;
                int r = v[i].second.second;

                while (cur <= l) {
                        if (d[cur] == 0) {
                                app.insert(d[cur]);
                                ans ++;
                        } else {
                                if (app.count(d[cur] - 1)) {
                                        app.insert(d[cur]);
                                        ans ++;
                                }
                        }

                        if (to[cur] != -1) {
                                uf.unite(cur, to[cur]);
                        }

                        if (cur) {
                                acc[cur] = acc[cur - 1] + (d[cur] == 0 ? uf.get(cur) : 0);
                        }

                        cur ++;
                }

                int aaa = ans - (x ? acc[x - 1] : 0);
                res[idx] = ;
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
