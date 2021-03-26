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

void solve() {
        int n, q, k;
        cin >> n >> q >> k;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<int> val(n);
        for (int i = 1; i < n - 1; i ++) {
                val[i] = a[i + 1] - a[i - 1] - 2;
        }
        vector<ll> acc(n);
        acc[0] = val[0];
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] + val[i];
        }
        while (q --) {
                int l, r;
                cin >> l >> r;
                l --, r --;
                ll res = 0;
                int len = r - l + 1;
                if (len == 1) {
                        cout << k - 1 << '\n';
                        continue;
                }
                if (l + 1 <= r - 1) {
                        res += acc[r - 1] - acc[l];
                }
                res += a[l + 1] - 1 - 1;
                res += k - a[r - 1] - 1;
                cout << res << '\n';
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
