#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int h, w;
        cin >> h >> w;
        vector<vector<char>> ans(h, vector<char> (w, 'B'));
        ans[h - 1][w - 1] = 'W';
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
