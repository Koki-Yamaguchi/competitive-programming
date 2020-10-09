#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        rep(i, n) {
                cin >> a[i];
                sum += a[i];
        }
        int l = 0, r = n - 1;
        int ans = 0, ansl = 0, ansr = 0;
        int lp = 0, rp = 0;
        while (true) {
                int cur = 0;
                lp = 0;
                while (cur <= rp && l <= r) {
                        ansl += a[l];
                        lp += a[l];
                        cur += a[l];
                        l ++;
                }
                ans ++;
                if (l > r) break;
                cur = 0;
                rp = 0;
                while (cur <= lp && l <= r) {
                        ansr += a[r];
                        rp += a[r];
                        cur += a[r];
                        r --;
                }
                ans ++;
                if (l > r) break;
        }
        assert(sum == ansl + ansr);
        cout << ans << " " << ansl << " " << ansr << '\n';
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
