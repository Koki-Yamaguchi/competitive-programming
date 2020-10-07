#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        string s, t;
        cin >> s >> t;
        int ans = 1e9;
        rep(i, s.size() - t.size() + 1) {
                int d = 0;
                for (int j = i; j < i + t.size(); j ++) {
                        d += s[j] != t[j - i];
                }
                ans = min(ans, d);
        }
        cout << ans << '\n';
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
