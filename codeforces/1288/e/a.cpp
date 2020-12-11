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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        vector<int> mi(n, 1e9), ma(n, -1);
        rep(i, m) {
                cin >> a[i];
                a[i] --;
                mi[a[i]] = min(mi[a[i]], 0);
        }
        fenwick_tree<int> ft(n + m);
        vector<int> pos(n);
        rep(i, n) {
                ft.add(m + i, 1);
                pos[i] = m + i;
        }
        int front = m;
        auto calc = [&]() {
                rep(i, n) {
                        int p = pos[i];
                        int idx = ft.sum(0, p) - ft.sum(0, front);
                        ma[i] = max(ma[i], idx);
                        mi[i] = min(mi[i], idx);
                }
        };
        calc(); // before
        rep(i, m) {
                int p = pos[a[i]];
                int idx = ft.sum(0, p) - ft.sum(0, front);
                ma[a[i]] = max(ma[a[i]], idx);
                mi[a[i]] = min(mi[a[i]], idx);
                ft.add(front - 1, 1);
                ft.add(p, -1);
                pos[a[i]] = front - 1;
                front --;
        }
        calc(); // after
        rep(i, n) {
                cout << mi[i] + 1 << " " << ma[i] + 1 << '\n';
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
