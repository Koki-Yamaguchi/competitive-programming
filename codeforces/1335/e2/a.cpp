#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        const int maa = 200;
        vector<vector<int>> pos(maa), acc(maa, vector<int> (n));
        rep(i, n) {
                cin >> a[i];
                a[i] --;
                pos[a[i]].push_back(i);
        }
        acc[a[0]][0] = 1;
        rep(i, n) if (i) {
                rep(j, maa) {
                        acc[j][i] = acc[j][i - 1] + (a[i] == j);
                }
        }
        int ans = 0;
        rep(i, maa) {
                ans = max(ans, acc[i][n - 1]);
        }
        rep(i, maa) {
                auto p = pos[i];
                int sz = acc[i][n - 1];
                rep(j, p.size()) {
                        int l = p[j];
                        if (j >= sz - 1 - j) {
                                break;
                        }
                        int r = p[sz - 1 - j];
                        rep(k, maa) {
                                int side = (j + 1) * 2;
                                int mid = acc[k][r - 1] - acc[k][l];
                                ans = max(ans, side + mid);
                        }
                }
        }
        cout << ans << '\n';
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
