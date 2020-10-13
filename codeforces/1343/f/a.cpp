#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> seg(n - 1);
        rep(i, n - 1) {
                int sz;
                cin >> sz;
                seg[i].resize(sz);
                rep(j, sz) {
                        cin >> seg[i][j];
                        seg[i][j] --;
                }
        }
        vector<int> ans;
        function<void (vector<int> &, vector<bool> &)> dfs = [&](vector<int> &cur, vector<bool> &used) {
                // check if no contradiction
                int len = cur.size();
                bool ng = false;
                rep(i, seg.size()) {
                        if (used[i]) continue;
                        set<int> segst(seg[i].begin(), seg[i].end());
                        bool f = false;
                        for (int j = len - 1; j >= 0; j --) {
                                if (segst.count(cur[j])) {
                                        if (f) {
                                                ng = true;
                                                break;
                                        }
                                } else {
                                        f = true;
                                }
                        }
                        if (ng) {
                                break;
                        }
                }
                if (ng) {
                        return;
                }

                // find the seg
                set<int> curst(cur.begin(), cur.end());
                rep(i, seg.size()) {
                        if (used[i]) continue;
                        int c = 0;
                        int nxt = -1;
                        rep(j, seg[i].size()) {
                                if (curst.count(seg[i][j])) {
                                        c ++;
                                } else {
                                        nxt = seg[i][j];
                                }
                        }
                        if (c + 1 == seg[i].size()) {
                                assert(nxt != -1);
                                cur.push_back(nxt);
                                used[i] = true;
                                if (cur.size() == n) {
                                        ans = cur;
                                        return;
                                }
                                dfs(cur, used);
                                cur.pop_back();
                                used[i] = false;
                        }
                }
        };
        vector<bool> used(n - 1);
        vector<int> cur;
        rep(i, n) {
                cur.push_back(i);
                dfs(cur, used);
                cur.pop_back();
        }
        assert(ans.size() == n);
        rep(i, n) {
                cout << ans[i] + 1 << " \n"[i == n - 1];
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
