#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long ans = -1e18;
        {
                long long res = 1;
                for (int i = n - 1; i >= n - 5; i --) {
                        res *= a[i];
                }
                ans = max(ans, res);
        }
        {
                long long res = 1;
                rep(i, 2) {
                        res *= a[i];
                }
                for (int i = n - 1; i >= n - 3; i --) {
                        res *= a[i];
                }
                ans = max(ans, res);
        }
        {
                long long res = 1;
                rep(i, 4) {
                        res *= a[i];
                }
                for (int i = n - 1; i >= n - 1; i --) {
                        res *= a[i];
                }
                ans = max(ans, res);
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
