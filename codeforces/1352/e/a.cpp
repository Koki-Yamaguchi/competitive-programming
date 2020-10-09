#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> acc(n + 1);
        rep(i, n) {
                cin >> a[i];
                acc[i + 1] = acc[i] + a[i];
        }
        vector<bool> app(n + 1, false);
        rep(j, n + 1) {
                rep(i, j - 1) {
                        if (acc[j] - acc[i] <= n) {
                                app[acc[j] - acc[i]] = true;
                        }
                }
        }
        int ans = 0;
        rep(i, n) {
                ans += app[a[i]];
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
