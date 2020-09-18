#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        int k, z;
        cin >> k >> z;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int ma = 0;
        int cur = 0;
        long long s = 0;
        long long ans = 0;
        rep(i, k + 1) {
                s += a[i];
                // cerr << "s, cur = " << s << " " << cur << endl;
                if (i) {
                        ma = max(ma, a[i] + a[i - 1]);
                        int hoge = i < n - 1 ? a[i] + a[i + 1] : 0;
                        int r = k - cur;
                        ans = max(ans, s + min((long long) z, (long long) (r / 2)) * ma);
                        ans = max(ans, s + min((long long) z, (long long) (r / 2)) * hoge);
                        if ((r & 1) && z > 0) {
                                ans = max(ans, s + min((long long) max(0, z - 1), (long long) (r / 2)) * ma + a[i - 1]);
                        }
                        // cerr << "ans = " << ans << endl;
                }
                cur ++;
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
