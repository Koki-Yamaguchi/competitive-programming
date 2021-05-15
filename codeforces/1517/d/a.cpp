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
        int n, m, k;
        cin >> n >> m >> k;
        const int inf = 1e9;
        vector<vector<int>> rcost(n, vector<int> (m, inf));
        vector<vector<int>> lcost(n, vector<int> (m, inf));
        rep(i, n) {
                rep(j, m - 1) {
                        cin >> rcost[i][j];
                        lcost[i][j + 1] = rcost[i][j];
                }
        }
        vector<vector<int>> dcost(n, vector<int> (m, inf));
        vector<vector<int>> ucost(n, vector<int> (m, inf));
        rep(i, n - 1) {
                rep(j, m) {
                        cin >> dcost[i][j];
                        ucost[i + 1][j] = dcost[i][j];
                }
        }
        if (k & 1) {
                rep(i, n) {
                        rep(j, m) {
                                cout << -1 << " ";
                        }
                        cout << '\n';
                }
                return;
        }
        const int mast = 10;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (mast + 1, inf)));
        rep(i, n) {
                rep(j, m) {
                        dp[i][j][0] = 0;
                }
        }
        for (int s = 1; s <= mast; s ++) {
                rep(i, n) {
                        rep(j, m) {
                                if (i) chmin(dp[i][j][s], dp[i - 1][j][s - 1] + ucost[i][j]);
                                if (i < n - 1) chmin(dp[i][j][s], dp[i + 1][j][s - 1] + dcost[i][j]);
                                if (j) chmin(dp[i][j][s], dp[i][j - 1][s - 1] + lcost[i][j]);
                                if (j < m - 1) chmin(dp[i][j][s], dp[i][j + 1][s - 1] + rcost[i][j]);
                        }
                }
        }
        rep(i, n) {
                rep(j, m) {
                        cout << 2 * dp[i][j][k / 2] << ' ';
                }
                cout << '\n';
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
