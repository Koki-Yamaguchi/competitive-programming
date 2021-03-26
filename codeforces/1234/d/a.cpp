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
        string s;
        cin >> s;
        int q;
        cin >> q;
        int n = s.size();
        vector<fenwick_tree<int>> accs(26, n + 1);
        rep(i, n) {
                int v = s[i] - 'a';
                accs[v].add(i, 1);
        }
        while (q --) {
                int t;
                cin >> t;
                if (t == 1) {
                        int pos;
                        char c;
                        cin >> pos >> c;
                        pos --;
                        int prev = s[pos] - 'a';
                        int cur = c - 'a';
                        accs[prev].add(pos, -1);
                        accs[cur].add(pos, 1);
                        s[pos] = c;
                } else {
                        int l, r;
                        cin >> l >> r;
                        l --;
                        int ans = 0;
                        rep(i, 26) {
                                int cnt = accs[i].sum(0, r) - accs[i].sum(0, l);
                                ans += (cnt > 0);
                        }
                        cout << ans << '\n';
                }
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
