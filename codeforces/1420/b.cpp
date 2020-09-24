#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        map<int, int> cnt;
        long long ans = 0;
        rep(i, n) {
                long long a;
                cin >> a;
                for (long long j = 50; j >= 0; j --) {
                        if (a & (1ll << j)) {
                                ans += cnt[j];
                                cnt[j] ++;
                        }
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
