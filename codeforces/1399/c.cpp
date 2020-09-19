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
        int ans = 0;
        for (int s = 2; s <= 100; s ++) {
                int res = 0;
                int l = 0;
                int r = n - 1;
                while (l < r) {
                        int o = s - a[l];
                        if (o == a[r]) {
                                l ++;
                                r --;
                                res ++;
                        } else if (o < a[r]) {
                                r --;
                        } else {
                                l ++;
                        }
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
