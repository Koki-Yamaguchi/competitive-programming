#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        if (m % 2 == 0) swap(n, m);
        int ans = 0;
        if (n % 2 == 0) {
                ans = ((n + 1) / 2) * m;
        } else {
                if (n < m) swap(n, m);
                ans += (n / 2) * m;
                ans += (m + 1) / 2;
        }
        cout << ans << endl;
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
