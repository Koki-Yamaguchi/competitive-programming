#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, k;
        cin >> n >> k;
        int lb = 0, ub = n + 1;
        while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                ll x = (ll) (mid + 1) * mid / 2;
                if (x >= k) {
                        ub = mid;
                } else {
                        lb = mid;
                }
        }
        ll r = (ll) (lb + 1) * lb / 2;
        string ans = string(n, 'a');
        ans[n - 2 - lb] = 'b';
        ans[n - 1 - (k - r - 1)] = 'b';
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
