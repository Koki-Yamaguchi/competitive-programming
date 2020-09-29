#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long a, b, x, y, nn;
        cin >> a >> b >> x >> y >> nn;
        long long ans = 1e18;
        rep(i, 2) {
                long long na = a, nb = b;
                long long n = nn;
                long long d = min(n, nb - y);
                nb -= d;
                n -= d;
                d = min(n, na - x);
                na -= d;
                n -= d;
                ans = min(ans, na * nb);
                swap(a, b);
                swap(x, y);
        }
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
