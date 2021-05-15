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

int ask(int l, int r) {
        cout << "? " << l + 1 << " " << r + 1 << endl;
        int s;
        cin >> s;
        return s;
}

void answer(int r) {
        cout << "! " << r + 1 << endl;
        return;
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
        int n, t;
        cin >> n >> t;
        fenwick_tree<int> ft(n);
        vector<int> memo(n, -1);
        rep(i, t) {
                int k;
                cin >> k;
                int lb = -1, ub = n;
                while (ub - lb > 1) {
                        int mid = (lb + ub) / 2;
                        int sum;
                        if (memo[mid] == -1) {
                                sum = ask(0, mid);
                                memo[mid] = sum - ft.sum(0, mid + 1);
                        } else {
                                sum = memo[mid] + ft.sum(0, mid + 1);
                        }
                        int zn = mid + 1 - sum;
                        if (zn <= k - 1) {
                                lb = mid;
                        } else {
                                ub = mid;
                        }
                }
                answer(lb + 1);
                ft.add(lb + 1, 1);
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
