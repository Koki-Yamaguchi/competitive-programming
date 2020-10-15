#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        rep(i, n) {
                cin >> a[i] >> b[i];
        }
        vector<ll> b_need(n);
        rep(i, n) {
                b_need[i] = max(0ll, a[i] - b[(i - 1 + n) % n]);
        }
        vector<ll> acc(n);
        acc[0] = b_need[0];
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] + b_need[i];
        }
        ll ans = 1e18 + 10;
        rep(i, n) {
                ll p = a[i] + (i ? acc[i - 1] : 0ll) + (acc[n - 1] - acc[i]);
                ans = min(ans, p);
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
