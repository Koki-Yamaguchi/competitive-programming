#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        vector<int> ns(3);
        rep(i, 3) {
                cin >> ns[i];
        }
        vector<vector<int>> v(3);
        rep(i, 3) {
                rep(j, ns[i]) {
                        int a;
                        cin >> a;
                        v[i].push_back(a);
                }
        }
        rep(i, 3) {
                sort(v[i].rbegin(), v[i].rend());
        }
        vector<vector<vector<int>>> dp(ns[0] + 1, vector<vector<int>> (ns[1] + 1, vector<int> (ns[2] + 1)));
        rep(i, ns[0] + 1) {
                rep(j, ns[1] + 1) {
                        rep(k, ns[2] + 1) {
                                if (i < ns[0] && j < ns[1]) {
                                        dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + v[0][i] * v[1][j]);
                                }
                                if (j < ns[1] && k < ns[2]) {
                                        dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + v[1][j] * v[2][k]);
                                }
                                if (i < ns[0] && k < ns[2]) {
                                        dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + v[0][i] * v[2][k]);
                                }
                        }
                }
        }
        int ans = 0;
        rep(i, ns[0] + 1) {
                rep(j, ns[1] + 1) {
                        rep(k, ns[2] + 1) {
                                ans = max(ans, dp[i][j][k]);
                        }
                }
        }
        cout << ans << "\n";
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
