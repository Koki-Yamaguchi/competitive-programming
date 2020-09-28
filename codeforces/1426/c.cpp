#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

int f(int x, int n) {
        if (x <= 0) return 1e9;
        return x - 1 + (n + x - 1) / x - 1;
}

int solve2(int n) {
        int ans = 1e9;
        for (int i = 0; i <= n; i ++) {
                ans = min(ans, f(i, n));
                // cerr << f(i, n) << endl;
        }
        return ans;
}

void solve() {
        /*
        rep(x, 500) if (x >= 2) {
               cerr << "x = " << x << endl;
               */
        int n;
        cin >> n;
        // n = x;
        /*
        if (n == 1) {
                cout << 0 << '\n';
                return;
        }
        int lb = 0, ub = 1e9 + 10;
        int cnt = 500;
        while (cnt --) {
                int l = (lb * 2 + ub) / 3;
                int r = (lb + ub * 2) / 3;
                if (f(l, n) < f(r, n)) {
                        ub = r;
                } else {
                        lb = l;
                }
        }
        // cerr << "lb = " << lb << endl;
        for (int i = lb - 5; i <= lb + 5; i ++) {
                ans = min(ans, f(i, n));
        }
        */
        int ans = 1e9;
        int sq = sqrt(n);
        for (int i = sq - 100; i <= sq + 100; i ++) {
                ans = min(ans, f(i, n));
        }
        /*
        int exp = solve2(n);
        if (ans != exp) {
                cout << "ERROR: " << ans << " " << exp << endl;
        }
        */
        cout << ans << '\n';
        // }
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
