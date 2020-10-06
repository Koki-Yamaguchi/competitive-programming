#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int> (w)), ans(h, vector<int> (w));
        rep(i, h) {
                rep(j, w) {
                        cin >> a[i][j];
                }
        }
        rep(i, h) {
                rep(j, w) {
                        vector<int> nxt = { i + 1, i - 1 };
                        int c = 0;
                        for (auto nx : nxt) {
                                c += (0 <= nx && nx < h);
                        }
                        nxt = { j + 1, j - 1 };
                        for (auto nx : nxt) {
                                c += (0 <= nx && nx < w);
                        }
                        if (a[i][j] > c) {
                                cout << "NO\n";
                                return;
                        }
                        ans[i][j] = c;
                }
        }
        cout << "YES\n";
        rep(i, h) {
                rep(j, w) {
                        cout << ans[i][j] << " \n"[j == w - 1];
                }
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
