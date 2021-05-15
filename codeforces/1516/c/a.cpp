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
        vector<int> a(n);
        int s = 0;
        rep(i, n) {
                cin >> a[i];
                s += a[i];
        }
        if (s & 1) {
                cout << 0 << '\n';
                return;
        }
        int half = s / 2;
        bitset<100010> dp;
        dp[0] = 1;
        rep(i, n) {
                auto nxt = dp;
                nxt |= dp << a[i];
                dp = nxt;
        }
        if (not dp[half]) {
                cout << 0 << '\n';
                return;
        }
        while (true) {
                rep(i, n) {
                        if (a[i] & 1) {
                                cout << 1 << '\n';
                                cout << i + 1 << '\n';
                                return;
                        }
                }
                bool all = true;
                rep(i, n) {
                        if (a[i] % 2 != 0) {
                                all = false;
                                break;
                        }
                }
                if (all) {
                        rep(i, n) {
                                a[i] /= 2;
                        }
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
