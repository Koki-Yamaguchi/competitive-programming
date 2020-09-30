#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> a(3, vector<int> (n));
        rep(i, 3) {
                rep(j, n) {
                        cin >> a[i][j];
                }
        }
        vector<int> p = {a[0][0]};
        rep(i, n) if (i) {
                if (i != n - 1) {
                        rep(j, 3) {
                                if (p.back() != a[j][i]) {
                                        p.push_back(a[j][i]);
                                        break;
                                }
                        }
                } else {
                        rep(j, 3) {
                                if (p.back() != a[j][i] && p[0] != a[j][i]) {
                                        p.push_back(a[j][i]);
                                        break;
                                }
                        }
                }
        }
        rep(i, n) {
                cout << p[i] << " \n"[i == n - 1];
        }
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
