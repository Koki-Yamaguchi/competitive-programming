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
        int n;
        cin >> n;
        vector<pair<int, int>> seg(n);
        rep(i, n) {
                cin >> seg[i].first >> seg[i].second;
        }
        vector<int> al;
        rep(i, n) {
                al.push_back(seg[i].first);
                al.push_back(seg[i].second);
        }
        sort(all(al));
        map<int, int> z;
        int k = 0;
        rep(i, al.size()) {
                if (z.count(al[i]) == 0) {
                        z[al[i]] = k ++;
                }
        }
        rep(i, n) {
                seg[i].first = z[seg[i].first];
                seg[i].second = z[seg[i].second];
        }
        sort(all(seg));
        fenwick_tree<int> ft(k);
        const int inf = 1e9;
        int ans = inf;
        rep(i, n) {
                int c = 0;
                c += ft.sum(seg[i].first, k);
                pair<int, int> r = {seg[i].second, inf};
                int p = upper_bound(all(seg), r) - seg.begin();
                c += p - i - 1;
                ft.add(seg[i].second, 1);
                assert(c <= n - 1);
                ans = min(ans, n - c - 1);
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
