#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n = 9;
        vector<vector<int>> s(n, vector<int> (n));
        rep(i, n) {
                string tmp;
                cin >> tmp;
                rep(j, tmp.size()) {
                        s[i][j] = tmp[j] - '0';
                        if (s[i][j] == 1) {
                                s[i][j] = 2;
                        }
                }
        }
        rep(i, n) {
                rep(j, n) {
                        cout << s[i][j];
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
