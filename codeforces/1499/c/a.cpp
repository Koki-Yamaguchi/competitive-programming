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
        vector<int> c(n);
        rep(i, n) {
                cin >> c[i];
        }
        ll ans = 1e18;
        int mio = 1e9 + 10;
        int mie = 1e9 + 10;
        ll acco = 0;
        ll acce = 0;
        int cnto = 0;
        int cnte = 0;
        rep(i, n) {
                if (i & 1) {
                        cnto ++;
                        mio = min(mio, c[i]);
                        acco += c[i];
                } else {
                        cnte ++;
                        mie = min(mie, c[i]);
                        acce += c[i];
                }
                ll c = 0;
                c += (acco - mio) + (ll) (n - (cnto - 1)) * mio;
                c += (acce - mie) + (ll) (n - (cnte - 1)) * mie;
                ans = min(ans, c);
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
