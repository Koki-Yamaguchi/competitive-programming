#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        rep(i, h) {
                cin >> s[i];
        }
        int ans = 0;
        rep(i, h) {
                ans += s[i][w - 1] == 'R';
        }
        rep(i, w) {
                ans += s[h - 1][i] == 'D';
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
