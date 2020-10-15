#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        reverse(all(a));
        ll s = 0;
        int ans = 0;
        rep(i, n) {
                s += a[i];
                int l = i + 1;
                if (s < (ll) x * l) {
                        break;
                }
                ans ++;
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
