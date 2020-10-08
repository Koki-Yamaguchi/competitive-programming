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
        vector<int> dp(n, 1);
        dp[0] = 1;
        rep(i, n) {
                int idx = i + 1;
                for (int j = i + idx; j < n; j += idx) {
                        if (a[i] < a[j]) {
                                dp[j] = max(dp[j], dp[i] + 1);
                        }
                }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
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
