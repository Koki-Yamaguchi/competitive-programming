#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> ans(n, vector<int> (n, 0));
        rep(i, n) {
                ans[i][i] = 1;
        }
        rep(i, n) {
                ans[n - 1 - i][i] = 1;
        }
        if (n & 1) {
                ans[n / 2 + 1][n / 2] = 1;
                ans[n / 2][n / 2 + 1] = 1;
        }
        rep(i, n) {
                rep(j, n) {
                        cout << ans[i][j] << " ";
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
