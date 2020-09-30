#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<long long> dp(2);
        rep(i, n) {
                vector<long long> nxt(2);
                nxt[0] = max(dp[0], dp[1] + a[i]);
                nxt[1] = max(dp[1], dp[0] - a[i]);
                swap(dp[0], nxt[0]);
                swap(dp[1], nxt[1]);
        }
        cout << max(dp[0], dp[1]) << '\n';
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
