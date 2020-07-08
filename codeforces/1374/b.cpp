#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
void solve() {
        int n;
        cin >> n;
        int ans = 0;
        while (n > 0 && n % 6 == 0) {
                n /= 6;
                ans ++;
        }
        int c = 0;
        while (n > 0 && n % 3 == 0) {
                n /= 3;
                c ++;
        }
        if (n == 1) {
                ans += c * 2;
                cout << ans << '\n';
        } else {
                cout << -1 << '\n';
        }
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