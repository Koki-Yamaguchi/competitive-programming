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
        long long ans = 0;
        rep(i, n) {
                int j = i;
                while (j < n && a[j] / abs(a[j]) == a[i] / abs(a[i])) {
                        j ++;
                }
                int ma = -1e9 - 5;
                for (int p = i; p < j; p ++) {
                        ma = max(ma, a[p]);
                }
                ans += ma;
                i = j - 1;
        }
        cout << ans << '\n';
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
