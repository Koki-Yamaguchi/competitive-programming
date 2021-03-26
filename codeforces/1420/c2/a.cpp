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

int calc_at_point(const vector<int> &a, int idx) {
        int n = a.size();
        if (idx < 0 || n <= idx) {
                return 0;
        }
        bool add = true, sub = true;
        if (idx == 0 || idx == n - 1) {
                sub = false;
        }
        if (idx > 0) {
                add = add && a[idx - 1] < a[idx];
                sub = sub && a[idx - 1] > a[idx];
        }
        if (idx < n - 1) {
                add = add && a[idx + 1] < a[idx];
                sub = sub && a[idx + 1] > a[idx];
        }
        if (add) {
                return a[idx];
        } else if (sub) {
                return -a[idx];
        } else {
                return 0;
        }
}

ll calc_at_range(const vector<int> &a, int l, int r) {
        ll res = 0;
        for (int i = l; i <= r; i ++) {
                res += calc_at_point(a, i);
        }
        return res;
}

void solve() {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        ll ans = calc_at_range(a, 0, n - 1);
        cout << ans << '\n';
        while (q --) {
                int l, r;
                cin >> l >> r;
                l --, r --;
                if (r - l >= 5) {
                        ans -= calc_at_range(a, l - 1, l + 1);
                        ans -= calc_at_range(a, r - 1, r + 1);
                        swap(a[l], a[r]);
                        ans += calc_at_range(a, l - 1, l + 1);
                        ans += calc_at_range(a, r - 1, r + 1);
                } else {
                        ans -= calc_at_range(a, l - 1, r + 1);
                        swap(a[l], a[r]);
                        ans += calc_at_range(a, l - 1, r + 1);
                }
                cout << ans << '\n';
        }
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
