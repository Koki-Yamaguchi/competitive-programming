#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

const int MOD = 998244353;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> seg(k);
        rep(i, k) {
                cin >> seg[i].first >> seg[i].second;
        }
        vector<long long> acc(n), ans(n);
        ans[0] = 1;
        rep(i, n) {
                if (i) {
                        (acc[i] += acc[i - 1]) %= MOD;
                }
                (ans[i] += acc[i]) %= MOD;
                rep(j, k) {
                        int l = seg[j].first;
                        int r = seg[j].second + 1;
                        if (i + l < n) {
                                (acc[i + l] += ans[i]) %= MOD;
                        }
                        if (i + r < n) {
                                ((acc[i + r] -= ans[i]) += MOD) %= MOD;
                        }
                }
        }
        cout << ans[n - 1] << '\n';
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
