#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long a, b;
        cin >> a >> b;
        if (b - a >= 10) {
                cout << 0 << '\n';
        } else {
                long long ans = 1;
                long long c = b - a;
                // cerr << "c = " << c << endl;
                while (c --) {
                        (ans *= b) %= 10;
                        b --;
                }
                cout << ans << '\n';
        }
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
