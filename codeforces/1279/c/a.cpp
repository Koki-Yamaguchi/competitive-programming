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
        vector<int> a(n), b(m);
        vector<int> vtoai(n, -1);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
                vtoai[a[i]] = i;
        }
        vector<int> vtobi(n, -1);
        rep(i, m) {
                cin >> b[i];
                b[i] --;
                vtobi[b[i]] = i;
        }
        vector<bool> in(m);
        int det = n;
        for (int i = n - 1; i >= 0; i --) {
                int bi = vtobi[a[i]];
                if (bi != -1 && bi < det) {
                        in[bi] = true;
                        det = min(det, bi);
                }
        }
        fenwick_tree<int> ft(n);
        ll ans = 0;
        rep(i, m) {
                int ai = vtoai[b[i]];
                if (not in[i]) {
                        ans ++;
                } else {
                        ans += 2 * (ai - ft.sum(0, ai)) + 1;
                }
                ft.add(ai, 1);
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
