#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        if (2 * a <= b) {
                cout << x * a + y * a << '\n';
        } else {
                long long m = min(x, y);
                cout << m * b + (x - m) * a + (y - m) * a << '\n';
        }
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
