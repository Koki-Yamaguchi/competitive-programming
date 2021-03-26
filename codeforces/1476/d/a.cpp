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
        int n;
        cin >> n;
        string s;
        cin >> s;
        UnionFind uf(2 * (n + 1));
        rep(i, n) {
                int u = i;
                int v = i + 1;
                int uu = u + n + 1;
                int vv = v + n + 1;
                if (s[i] == 'L') {
                        uf.unite(uu, v);
                } else {
                        uf.unite(vv, u);
                }
        }
        rep(i, n + 1) {
                cout << uf.get(i) << ' ';
        }
        cout << '\n';
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
