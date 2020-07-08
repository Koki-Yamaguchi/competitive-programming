#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
void solve() {
        int x, y, n;
        cin >> x >> y >> n;
        n -= y;
        int ans = (n / x) * x + y;
        cout << ans << '\n';
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