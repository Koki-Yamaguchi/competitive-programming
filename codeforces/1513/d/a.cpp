#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> ostream& operator << (ostream& os, const set<T> &p) { os << "{"; for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << *it; } os << "}"; return os; }
template<typename T, typename U> ostream& operator << (ostream& os, const map<T, U> &p) { for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << "{" << (*it).first << ": " << (*it).second << "}"; } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

long long mygcd(long long a, long long b) {
        while (b) {
                a %= b;
                swap(a, b);
        }
        return a;
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
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                if (a[i] == 1) {
                        cout << n - 1 << '\n';
                        return;
                }
        }
        // a[i] >= 2
        ll ans = 0;
        vector<vector<int>> b;
        b.push_back(vector<int> {a[0]});
        rep(i, n - 1) {
                if (mygcd(a[i], a[i + 1]) == 1) {
                        ans += p;
                        b.push_back(vector<int> {a[i + 1]});
                } else {
                        b.back().push_back(a[i + 1]);
                }
        }
        for (auto v : b) {
                int len = v.size();
                if (len == 1) {
                        continue;
                }
                UnionFind uf(len);
                vector<int> idxs(len); rep(i, len) idxs[i] = i;
                sort(all(idxs), [&](auto a, auto b) {
                        return v[a] < v[b];
                });
                vector<bool> used(len - 1); // right edge of idx
                for (auto idx : idxs) {
                        int val = v[idx];
                        if (val >= p) {
                                break;
                        }
                        for (int i = idx - 1; i >= 0; i --) {
                                if (v[i] % val != 0) {
                                        break;
                                }
                                if (used[i]) {
                                        break;
                                }
                                used[i] = true;
                                ans += val;
                                uf.unite(i, idx);
                        }
                        for (int i = idx + 1; i < len; i ++) {
                                if (v[i] % val != 0) {
                                        break;
                                }
                                if (used[i - 1]) {
                                        break;
                                }
                                used[i - 1] = true;
                                ans += val;
                                uf.unite(i, idx);
                        }
                }
                ans += (ll) p * (uf.get() - 1);
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
