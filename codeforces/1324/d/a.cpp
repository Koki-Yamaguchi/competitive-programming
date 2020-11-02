#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;

}               

// verified by https://judge.yosupo.jp/problem/point_add_range_sum
template<class T> class fenwick_tree {
        int _n;
        vector<T> data;
        T sum(int r) {
                T s = 0;
                while (r > 0) {
                        s += data[r - 1];
                        r -= r & -r;
                }
                return s;
        }
public:
        fenwick_tree(int n) : _n(n), data(n) {}
        void add(int p, T x) {
                assert(0 <= p && p < _n);
                p ++;
                while (p <= _n) {
                        data[p - 1] += x;
                        p += p & -p;
                }
        }
        T sum(int l, int r) { // [l, r)
                assert(0 <= l && l <= r && r <= _n);
                return sum(r) - sum(l);
        }
};

void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        vector<int> al;
        rep(i, n) {
                al.push_back(a[i] - b[i]);
                al.push_back(b[i] - a[i]);
        }
        sort(all(al));
        map<int, int> z;
        int k = 1;
        rep(i, al.size()) {
                if (z.count(al[i]) == 0) z[al[i]] = k ++;
        }
        fenwick_tree<int> ft(2 * n + 10);
        ll ans = 0;
        rep(i, n) {
                ans += ft.sum(z[b[i] - a[i]] + 1, 2 * n + 10);
                ft.add(z[a[i] - b[i]], 1);
        }
        cout << ans << '\n';
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
