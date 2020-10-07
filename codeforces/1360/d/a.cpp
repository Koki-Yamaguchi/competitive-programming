#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> cands;
        for (int i = 1; (long long) i * i <= n; i ++) {
                if (n % i == 0) {
                        cands.push_back(i);
                        cands.push_back(n / i);
                }
        }
        int ans = 1e9 + 10;
        rep(i, cands.size()) {
                if (cands[i] <= k) {
                        ans = min(ans, n / cands[i]);
                }
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
