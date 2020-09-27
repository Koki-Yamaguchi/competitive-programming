#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int mi = 1e9;
        int idx = -1;
        rep(i, n) {
                cin >> a[i];
                if (mi > a[i]) {
                        mi = min(mi, a[i]);
                        idx = i;
                }
        }
        int ans = 0;
        rep(i, n) {
                if (idx != i) {
                        ans += (k - a[i]) / mi;
                }
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
