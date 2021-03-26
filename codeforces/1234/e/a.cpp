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
        rep(i, m) {
                cin >> a[i];
                a[i] --;
        }
        fenwick_tree<int> ft(n);
        vector<ll> diff(n);
        ll ans = 0;
        rep(i, m - 1) {
                int x = a[i];
                int y = a[i + 1];
                ans += abs(y - x);
        }
        rep(i, m - 1) {
                int x = a[i];
                int y = a[i + 1];
                if (x == y) {
                        continue;
                }
                if (x > y) {
                        swap(x, y);
                }
                int l = x + 1;
                int r = y;
                if (l < r) {
                        ft.add(l, -1);
                        ft.add(r, 1);
                }
                diff[x] += x;
                diff[y] += 2 * x - y + 1;
        }
        rep(i, n) {
                diff[i] += ft.sum(0, i + 1);
                cout << ans + diff[i] << " ";
        }
        cout << '\n';
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
