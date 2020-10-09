#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        vector<long long> f;
        long long cur = 2;
        long long n = 1;
        while (true) {
                f.push_back(cur);
                cur += 3ll * n + 2;
                if (cur > 1e9 + 1) {
                        break;
                }
                n ++;
        }
        reverse(f.begin(), f.end());
        int ans = 0;
        cin >> n;
        rep(i, f.size()) {
                if (n >= f[i]) {
                        ans += n / f[i];
                        n -= (n / f[i]) * f[i];
                }
        }
        cout << ans << '\n';
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
