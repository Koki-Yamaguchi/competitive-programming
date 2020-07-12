#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, r;
        cin >> n >> r;
        int s = min(r, n - 1);
        long long ans = (long long) (s + 1) * s / 2 + max((min(r, n) - n + 1), 0);
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
