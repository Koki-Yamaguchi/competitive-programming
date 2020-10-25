#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        int b = 0, e = 0;
        vector<ll> acc(n);
        acc[0] = a[0];
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] + a[i];
        }
        ll ans = 1e18;
        while (true) {
                while (e + 1 < n && a[e] == a[e + 1]) {
                        e ++;
                }
                ll v = a[b];
                int c = e - b + 1;
                if (c >= k) {
                        cout << 0 << '\n';
                        return;
                }
                int lc = b;
                ll lval = (v - 1) * lc;
                ll lacc = (b ? acc[b - 1] : 0);
                assert(lval >= lacc);
                ll lneed = lval - lacc;
                int rc = n - 1 - e;
                ll rval = (v + 1) * rc;
                ll racc = acc[n - 1] - acc[e];
                assert(rval <= racc);
                ll rneed = racc - rval;
                if (lc + c >= k) {
                        ans = min(ans, lneed + k - c);
                }
                if (rc + c >= k) {
                        ans = min(ans, rneed + k - c);
                }
                ans = min(ans, lneed + rneed + k - c);
                b = e + 1;
                e = e + 1;
                if (b == n) {
                        break;
                }
        }
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
