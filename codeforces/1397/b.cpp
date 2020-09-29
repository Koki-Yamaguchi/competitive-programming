#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<long long> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        if (n == 1) {
                cout << abs(a[0] - 1) << '\n';
                return;
        }
        sort(a.begin(), a.end());
        vector<vector<long long>> pw(100000, vector<long long> (60, -1));
        rep(i, 100000) pw[i][0] = 1;
        rep(i, 100000) {
                rep(j, 60) if (j) {
                        if (pw[i][j - 1] != -1) {
                                if (pw[i][j - 1] < 1e10) {
                                        pw[i][j] = pw[i][j - 1] * i;
                                        // cerr << "i, j, pw = " << i << " " << j << " " << pw[i][j] << endl;
                                }
                        }
                }
        }
        if (n < 60) {
                long long ans = 1e18;
                for (long long b = 1; b < 100000; b ++) {
                        long long res = 0;
                        rep(i, n) {
                                if (pw[b][i] == -1) {
                                        res = 1e18;
                                        break;
                                }
                                res += abs(a[i] - (long long) pw[b][i]);
                        }
                        ans = min(ans, res);
                }
                cout << ans << '\n';
        } else {
                long long ans = 0;
                rep(i, n) {
                        ans += abs(a[i] - 1);
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
