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
        const int mmm = 5;
        vector<vector<int>> cur(mmm, vector<int> (mmm));
        vector<int> cnt(n);
        cnt[0] = (s[0] == a);
        rep(i, n) if (i) {
                cnt[i] = cnt[i - 1] + (s[i] == a);
        }
        rep(i, n) {
                cerr << "i = " << i << endl;
                vector<vector<int>> nxt(mmm, vector<int> (mmm));
                rep(ai, mmm) {
                        rep(bi, mmm) {
                                if (s[i] == b && (ai + bi) <= i + 1) {
                                        nxt[ai][bi] = max(nxt[ai][bi], cur[ai][bi] + (i ? cnt[i - 1] : 0) + ai);
                                } else if (ai + bi <= i + 1) {
                                        nxt[ai][bi] = max(nxt[ai][bi], cur[ai][bi]);
                                }
                                if (s[i] != a && ai + 1 < mmm && (ai + 1 + bi) <= i + 1) {
                                        nxt[ai + 1][bi] = max(nxt[ai + 1][bi], cur[ai][bi]);
                                }
                                if (s[i] != b && bi + 1 < mmm && (ai + bi + 1) <= i + 1) {
                                        nxt[ai][bi + 1] = max(nxt[ai][bi + 1], cur[ai][bi] + (i ? cnt[i - 1] : 0) + ai);
                                }
                        }
                }
                rep(ai, mmm) {
                        rep(bi, mmm) {
                                printf("nxt[%d][%d] = %d\n", ai, bi, nxt[ai][bi]);
                        }
                }
                swap(cur, nxt);
        }
        int ans = 0;
        rep(i, mmm) {
                rep(j, mmm) {
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
