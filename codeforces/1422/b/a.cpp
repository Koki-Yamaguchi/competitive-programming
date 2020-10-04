#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int> (w));
        rep(i, h) {
                rep(j, w) {
                        cin >> a[i][j];
                }
        }
        long long ans = 0;
        for (int i = 0; i <= (h - 1) / 2; i ++) {
                for (int j = 0; j <= (w - 1) / 2; j ++) {
                        vector<int> same;
                        long long lt = a[i][j];
                        same.push_back(lt);
                        if (h % 2 == 0 || i != h / 2) {
                                long long lb = a[h - 1 - i][j];
                                same.push_back(lb);
                        }
                        if (w % 2 == 0 || j != w / 2) {
                                long long rt = a[i][w - 1 - j];
                                same.push_back(rt);
                        }
                        if ((h % 2 == 0 || i != h / 2) && (w % 2 == 0 || j != w / 2)) {
                                long long rb = a[h - 1 - i][w - 1 - j];
                                same.push_back(rb);
                        }
                        sort(same.begin(), same.end());
                        long long m = same[same.size() / 2];
                        rep(i, same.size()) {
                                ans += abs(m - same[i]);
                        }
                }
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
