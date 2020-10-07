#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long ans = -1e18;
        ans = max(ans, a * c);
        ans = max(ans, a * d);
        ans = max(ans, b * c);
        ans = max(ans, b * d);
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
