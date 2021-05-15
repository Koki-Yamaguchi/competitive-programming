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

#ifdef LOCAL
const int BMAX = 10 + 1;
#else
const int BMAX = 10000 + 1;
#endif

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<bitset<BMAX>>> dp(n, vector<bitset<BMAX>> (m));
        dp[0][0][0] = 1;
        rep(y, n) {
                rep(x, m) {
                        if (y + 1 < n) dp[y + 1][x] |= (dp[y][x] << (x + 1));
                        if (x + 1 < m) dp[y][x + 1] |= (dp[y][x] << (y + 1));
                }
        }
        cout << (dp[n - 1][m - 1][k] ? "YES" : "NO") << '\n';
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
