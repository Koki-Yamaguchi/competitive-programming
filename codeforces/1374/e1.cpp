#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> t(n), a(n), b(n);
        vector<vector<int>> v(3);
        rep(i, n) {
                cin >> t[i] >> a[i] >> b[i];
                if (a[i] && !b[i]) {
                        v[0].push_back(t[i]);
                } else if (!a[i] && b[i]) {
                        v[1].push_back(t[i]);
                } else if (a[i] && b[i]) {
                        v[2].push_back(t[i]);
                }
        }
        rep(i, 3) {
                sort(v[i].begin(), v[i].end());
        }
        vector<vector<long  long>> acc(2, vector<long long> (max(v[0].size(), v[1].size())));
        rep(i, 2) {
                if (v[i].size() > 0) {
                        acc[i][0] = v[i][0];
                        rep(j, v[i].size()) if (j) {
                                acc[i][j] = acc[i][j - 1] + v[i][j];
                        }
                }
        }
        long long ans = 1e18 + 5;
        long long s = 0;
        rep(x, min((int) v[2].size() + 1, k + 1)) {
                if (x > 0) s += v[2][x - 1];
                int r = k - x;
                if (r == 0) {
                        ans = min(ans, s);
                }
                r --;
                if (r >= 0 && r < v[0].size() && r < v[1].size()) {
                        ans = min(ans, s + acc[0][r] + acc[1][r]);
                }
        }
        if (ans == (long long) 1e18) {
                ans = -1;
        }
        cout << ans << '\n';
}
 
int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t = 1;
        // cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}