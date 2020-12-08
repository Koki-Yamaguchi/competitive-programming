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
        int tn;
        cin >> tn;
        vector<pair<int, int>> a;
        int n = tn;
        ll ans = 0;
        rep(i, tn) {
                int sz;
                cin >> sz;
                int mi = 1e9, ma = -1;
                bool ok = false;
                rep(j, sz) {
                        int b;
                        cin >> b;
                        mi = min(mi, b);
                        ma = max(ma, b);
                        if (mi < b) {
                                ok = true;
                        }
                }
                if (ok) {
                        ans += n * 2 - 1;
                        n --;
                        continue;
                }
                a.push_back({mi, ma});
        }
        const int maa = 1e6 + 10;
        fenwick_tree<int> ft(maa), ft2(maa);
        rep(i, n) {
                ans += ft.sum(0, a[i].second);
                ft.add(a[i].first, 1);
        }
        reverse(all(a));
        rep(i, n) {
                ans += ft2.sum(0, a[i].second);
                ft2.add(a[i].first, 1);
        }
        rep(i, n) {
                if (a[i].first != a[i].second) {
                        ans ++;
                }
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
