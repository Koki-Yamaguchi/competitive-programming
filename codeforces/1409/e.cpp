#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n);
        rep(i, n) {
                cin >> x[i];
        }
        rep(i, n) {
                cin >> y[i];
        }
        sort(x.begin(), x.end());
        vector<int> val(n), nxt(n);
        rep(l, n) {
                int lv = x[l];
                int r = upper_bound(x.begin(), x.end(), lv + k) - x.begin();
                nxt[l] = r;
                r = max(l, r - 1);
                val[l] = r - l + 1;
        }
        vector<int> ma(n);
        ma[n - 1] = val[n - 1];
        for (int i = n - 2; i >= 0; i --) {
                ma[i] = max(val[i], ma[i + 1]);
        }
        int ans = 0;
        rep(i, n) {
                ans = max(ans, val[i] + (nxt[i] < n ? ma[nxt[i]] : 0));
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
