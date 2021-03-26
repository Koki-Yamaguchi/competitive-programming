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
        vector<int> y, x;
        rep(i, 2 * n) {
                int ty, tx;
                cin >> ty >> tx;
                if (ty == 0) {
                        x.push_back(tx);
                } else {
                        y.push_back(ty);
                }
        }
        long double ans = 0;
        sort(all(y), [&](const int a, const int b) {
                return abs(a) > abs(b);
        });
        sort(all(x), [&](const int a, const int b) {
                return abs(a) > abs(b);
        });
        rep(i, n) {
                ans += sqrt((ll) x[i] * x[i] + (ll) y[i] * y[i]);
        }
        cout << setprecision(17) << ans << "\n";
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
