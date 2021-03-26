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
        int n;
        cin >> n;
        vector<ll> c(n);
        rep(i, n) {
                cin >> c[i];
        }
        vector<ll> a(n), b(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        vector<ll> in(n), out(n);
        rep(i, n) {
                if (i == n - 1) {
                        in[i] = c[i] - 1;
                }
                if (i < n - 1) {
                        if (a[i + 1] > b[i + 1]) {
                                swap(a[i + 1], b[i + 1]);
                        }
                        in[i] = b[i + 1] - a[i + 1];
                        out[i] = c[i] - b[i + 1] + a[i + 1] - 1;
                }
                if (i == 0) {
                        out[i]= 0;
                }
        }
        vector<ll> val(n);
        ll acc = 0;
        const ll inf = 1e12;
        rep(i, n) {
                val[i] = 2ll * i + in[i] + out[i] + acc;
                acc += (in[i] == 0 ? -inf : out[i]);
        }
        vector<ll> ma(n);
        ma[n - 1] = val[n - 1];
        for (int i = n - 2; i >= 0; i --) {
                ma[i] = max(ma[i + 1], val[i]);
        }
        ll ans = 0;
        acc = 0;
        rep(i, n - 1) {
                acc += (in[i] == 0 ? -inf : out[i]);
                ll res = -2ll * i + in[i] - acc;
                ans = max(ans, res + (i + 1 < n ? ma[i + 1] : 0));
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
