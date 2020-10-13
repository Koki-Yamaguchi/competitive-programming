#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int ans = 0;
        rep(i, n - 1) {
                ll d = a[i] - a[i + 1];
                if (d <= 0) continue;
                int ma = 0;
                rep(i, 40) {
                        if ((d >> i) & 1) {
                                ma = max(ma, i);
                        }
                }
                a[i + 1] = a[i];
                ans = max(ans, ma + 1);
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
