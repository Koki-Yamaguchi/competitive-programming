#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        long long ans = 0;
        vector<int> cnt(n);
        rep(i, n) {
                long long pair_cnt = 0;
                for (int j = i + 1; j < n; j ++) {
                        if (a[i] == a[j]) {
                                ans += pair_cnt;
                        }
                        pair_cnt += cnt[a[j]];
                }
                cnt[a[i]] ++;
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
