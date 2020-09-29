#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        char a = t[0];
        char b = t[1];
        vector<vector<int>> cur(201, vector<int> (201));
        vector<int> cnt(n);
        cnt[0] = (s[0] == a);
        rep(i, n) if (i) {
                cnt[i] = cnt[i - 1] + (s[i] == a);
        }
        rep(i, n) {
                vector<vector<int>> nxt(201, vector<int> (201));
                rep(ai, 201) {
                        rep(bi, 201) {
                                if (s[i] == b) {
                                        nxt[ai][bi] = max(nxt[ai][bi], cur[ai][bi] + (i ? cnt[i - 1] : 0) + ai);
                                } else {
                                        nxt[ai][bi] = max(nxt[ai][bi], cur[ai][bi]);
                                }
                                if (s[i] != a && (ai + 1 + bi) <= k && ai + 1 < 201) {
                                        nxt[ai + 1][bi] = max(nxt[ai + 1][bi], cur[ai][bi]);
                                }
                                if (s[i] != b && (ai + bi + 1) <= k && bi + 1 < 201) {
                                        nxt[ai][bi + 1] = max(nxt[ai][bi + 1], cur[ai][bi] + (i ? cnt[i - 1] : 0) + ai);
                                }
                        }
                }
                swap(cur, nxt);
        }
        int ans = 0;
        rep(i, 201) {
                rep(j, 201) {
                        if (i + j <= k) {
                                ans = max(ans, cur[i][j]);
                        }
                }
        }
        cout << ans << '\n';
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
