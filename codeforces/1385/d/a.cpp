#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 1e9;
        function<void (const string &, int, int, int, int)> dfs = [&](const string &s, int l, int r, int c, int sum) {
                char ch = 'a' + c;
                if (l + 1 == r) {
                        int res = s[l] != ch;
                        ans = min(ans, sum + res);
                        return;
                }
                int m = (l + r) / 2;
                int resl = 0, resr = 0;
                for (int i = l; i < m; i ++) {
                        resl += s[i] != ch;
                }
                for (int i = m; i < r; i ++) {
                        resr += s[i] != ch;
                }
                dfs(s, l, m, c + 1, sum + resr);
                dfs(s, m, r, c + 1, sum + resl);
        };
        dfs(s, 0, n, 0, 0);
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
