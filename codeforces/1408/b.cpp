#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int c = 105;
        int ans = 0;
        while (c --) {
                int cur = 1;
                int last = a[0];
                rep(i, n) {
                        a[i] -= last;
                        /*
                        cerr << "last = " << last << endl;
                        cerr << "cur = " << cur << endl;
                        cerr << "a[i], a[i + 1] = " << (a[i] + last) << " " << a[i + 1] << endl;
                        */
                        if (i < n - 1 && (a[i] + last) < a[i + 1] && cur < k) {
                                cur ++;
                                last = a[i + 1];
                        }
                }
                ans ++;
                bool ok = true;
                rep(i, n) {
                        ok = ok && (a[i] == 0);
                }
                if (ok) break;
        }
        if (ans == 105) ans = -1;
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
