#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int h, w, sy, sx;
        cin >> h >> w >> sy >> sx;
        sy --, sx --;
        vector<pair<int, int>> ans;
        ans.emplace_back(sy, sx);
        rep(i, w) {
                if (i != sx) {
                        ans.emplace_back(sy, i);
                }
        }
        int y = sy + 1;
        bool f = true;
        while (true) {
                if (f) {
                        for (int i = w - 1; i >= 0; i --) {
                                ans.emplace_back(y, i);
                        }
                } else {
                        rep(i, w) {
                                ans.emplace_back(y, i);
                        }
                }
                y = (y + 1) % h;
                if (y == sy) break;
                f = !f;
        }
        rep(i, ans.size()) {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
