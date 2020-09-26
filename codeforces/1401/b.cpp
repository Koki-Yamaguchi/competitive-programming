#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        vector<int> a(3), b(3);
        rep(i, 3) {
                cin >> a[i];
        }
        rep(i, 3) {
                cin >> b[i];
        }
        int p = min(a[2], b[1]);
        int ans = p * 2;
        a[2] -= p;
        b[1] -= p;
        int r = a[1];
        int c = b[0] + b[1];
        if (r > c) {
                ans -= (r - c) * 2;
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
