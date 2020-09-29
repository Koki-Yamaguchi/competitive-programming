#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans;
        int mi = 1e9;
        for (int f = 1; f <= x; f ++) {
                for (int d = 1; d <= y - x; d ++) {
                        int cur = f;
                        bool usex = false, usey = false;
                        int nn = n - 1;
                        vector<int> res;
                        res.push_back(cur);
                        if (cur == x) usex = true;
                        while (nn --) {
                                cur += d;
                                if (cur == x) usex = true;
                                if (cur == y) usey = true;
                                res.push_back(cur);
                        }
                        if (usex && usey && res.back() < mi) {
                                mi = res.back();
                                ans = res;
                        }
                }
        }
        rep(i, n) {
                cout << ans[i] << " \n"[i == n - 1];
        }
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
