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
        vector<ll> a(n), b(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        vector<ll> acc(n), racc(n);
        acc[0] = a[0] * b[0];
        racc[n - 1] = a[n - 1] * b[n - 1];
        for (int i = 1; i < n; i ++) {
                acc[i] = acc[i - 1] + a[i] * b[i];
        }
        for (int i = n - 2; i >= 0; i --) {
                racc[i] = racc[i + 1] + a[i] * b[i];
        }
        ll ans = acc[n - 1];
        rep(c, n) {
                ll prod = a[c] * b[c];
                for (int rad = 1; rad < n; rad ++) {
                        int l = c - rad;
                        int r = c + rad;
                        if (l < 0 || l >= n || r < 0 || r >= n) {
                                break;
                        }
                        prod += a[l] * b[r];
                        prod += a[r] * b[l];
                        ans = max(ans, prod + (l ? acc[l - 1] : 0) + (r + 1 < n ? racc[r + 1] : 0));
                }
                prod = 0;
                for (int rad = 1; rad < n; rad ++) {
                        int l = c - rad;
                        int r = c + rad - 1;
                        if (l < 0 || l >= n || r < 0 || r >= n) {
                                break;
                        }
                        prod += a[l] * b[r];
                        prod += a[r] * b[l];
                        ans = max(ans, prod + (l ? acc[l - 1] : 0) + (r + 1 < n ? racc[r + 1] : 0));
                }
        }
        cout << ans << "\n";
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
