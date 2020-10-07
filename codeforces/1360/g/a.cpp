#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int h, w, a, b;
        cin >> h >> w >> a >> b;
        if (a * h != b * w) {
                cout << "NO\n";
                return;
        }
        cout << "YES\n";
        int cur = 0;
        vector<vector<char>> ans(h, vector<char> (w, '0'));
        rep(i, h) {
                for (int j = cur; j < cur + a; j ++) {
                        ans[i][j % w] = '1';
                }
                cur += a;
        }
        rep(i, h) {
                rep(j, w) {
                        cout << ans[i][j];
                }
                cout << '\n';
        }
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
