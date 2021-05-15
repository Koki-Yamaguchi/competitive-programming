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
        ll c;
        cin >> n >> c;
        vector<int> a(n), b(n - 1);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n - 1) {
                cin >> b[i];
        }
        ll ans = 1e12;
        ll cur = 0;
        ll curd = 0;
        rep(i, n) {
                ans = min(ans, curd + ((c - cur) + a[i] - 1) / a[i]);
                if (i < n - 1) {
                        ll need = b[i] - cur;
                        if (need > 0) {
                                ll d = (need + a[i] - 1) / a[i];
                                curd += d;
                                cur += a[i] * d;
                        }
                        assert(cur >= b[i]);
                        cur -= b[i];
                        curd ++;
                }
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
