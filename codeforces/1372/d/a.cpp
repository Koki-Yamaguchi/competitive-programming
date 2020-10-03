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
        vector<long long> dp0(2), dp1(2);
        rep(i, n) {
                vector<long long> nxt0(2), nxt1(2);
                rep(j, 2) {
                        nxt0[j] = dp1[j];
                        nxt1[j] = dp0[j] + a[i];
                }
                nxt1[1] = max(nxt1[1], dp1[0] + a[i]);
                swap(dp0, nxt0);
                swap(dp1, nxt1);
        }
        long long ans = 0;
        rep(i, 2) {
                ans = max(ans, dp0[i]);
                ans = max(ans, dp1[i]);
        }
        cout << ans << '\n';
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
