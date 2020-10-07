#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

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
        int n, q;
        cin >> n >> q;
        n -= 2;
        long long black = (long long) n * n;
        int xmi = 0, ymi = 0;
        long long white = 0;
        fenwick_tree<long long> ftx(n + 1), fty(n + 1);
        while (q --) {
                int t, v;
                cin >> t >> v;
                v = (n + 2) - v - 1;
                if (t == 1) {
                        int x = v;
                        int y = ftx.sum(0, x + 1);
                        white += n - y;
                        if (x + 1 > xmi) {
                                int prev = xmi;
                                xmi = x + 1;
                                fty.add(y, xmi - prev);
                        }
                } else {
                        int y = v;
                        int x = fty.sum(0, y + 1);
                        white += n - x;
                        if (y + 1 > ymi) {
                                int prev = ymi;
                                ymi = y + 1;
                                ftx.add(x, ymi - prev);
                        }
                }
        }
        cout << black - white << '\n';
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
