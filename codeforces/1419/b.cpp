#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long n = 1;
        long long b = 2;
        int ans = 0;
        long long x;
        cin >> x;
        while (x > 0) {
                long long num = n * (n + 1) / 2;
                x -= num;
                if (x < 0) {
                        break;
                }
                ans ++;
                n += b;
                b *= 2;
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
