#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        vector<vector<bool>> valid(n, vector<bool> (n));
        for (int i = n - 1; i >= 0; i --) {
                for (int j = n - 1; j >= 0; j --) {
                        if (i == n - 1 || j == n - 1) {
                                if (s[i][j] == '1') {
                                        valid[i][j] = true;
                                }
                        } else {
                                valid[i][j] = ((valid[i + 1][j] || valid[i][j + 1]) && s[i][j] == '1');
                        }
                        if (!valid[i][j] && s[i][j] == '1') {
                                cout << "NO\n";
                                return;
                        }
                }
        }
        cout << "YES" << '\n';
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
