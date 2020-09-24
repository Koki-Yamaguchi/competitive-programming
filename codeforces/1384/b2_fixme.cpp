#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n + 2);
        d[0] = d[n + 1] = -10000000;
        for (int i = 1; i <= n; i ++) {
                cin >> d[i];
        }
        vector<int> p(2 * k);
        rep(i, k + 1) {
                p[i] = i;
        }
        for (int i = k + 1; i < 2 * k; i ++) {
                p[i] = 2 * k - i;
        }
        vector<int> dp(n + 2, -1);
        dp[0] = k;
        rep(i, n + 1) {
                if (dp[i] == -1) {
                        break;
                }
                if (d[i + 1] + k <= l) {
                        dp[i + 1] = k;
                } else {
                        int need = d[i + 1] + k - l;
                        if (dp[i] >= k) {
                                dp[i + 1] = max(2 * k - need, dp[i] + 1);
                                dp[i + 1] %= 2 * k;
                        } else {
                                if (need < dp[i] + 1) {
                                        dp[i + 1] = -1;
                                } else {
                                        dp[i + 1] = dp[i] + 1;
                                }
                        }
                }
        }
        puts(dp[n + 1] == -1 ? "No": "Yes");

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

