#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<vector<int>> dp(n + 1, vector<int> (2, 1e9)); // friend: 0
        dp[0][1] = 0;
        rep(i, n) {
                // cerr << "i = " << i << endl;
                if (a[i] == 1) {
                        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1);
                        if (i) dp[i + 1][0] = min(dp[i + 1][0], dp[i - 1][1] + (a[i - 1] == 1) + 1);
                } else {
                        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
                        if (i) dp[i + 1][0] = min(dp[i + 1][0], dp[i - 1][1] + (a[i - 1] == 1));
                }
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
                if (i) dp[i + 1][1] = min(dp[i + 1][1], dp[i - 1][0]);
                // cerr << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
