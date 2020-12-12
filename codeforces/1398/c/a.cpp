#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        string s; cin >> s;
        vector<int> a(n);
        rep(i, n) {
                a[i] = s[i] - '0' - 1;
        }
        map<long long, int> cnt;
        cnt[0] = 1;
        long long acc = 0, ans = 0;
        rep(i, n) {
                acc += a[i];
                ans += cnt[acc];
                cnt[acc] ++;
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
