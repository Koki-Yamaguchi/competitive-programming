#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int h, w;
        cin >> h >> w;
        vector<string> tmp(h);
        rep(i, h) {
                cin >> tmp[i];
        }

        vector<vector<int>> s;
        if (h > w) {
                s.resize(w);
                rep(i, w) s[i].resize(h);
                rep(i, h) {
                        rep(j, w) {
                                s[j][i] = tmp[i][j] - '0';
                        }
                }

                swap(h, w);
        } else {
                s.resize(h);
                rep(i, h) s[i].resize(w);
                rep(i, h) {
                        rep(j, w) {
                                s[i][j] = tmp[i][j] - '0';
                        }
                }
        }

        if (h >= 4) {
                cout << -1 << '\n';
                return;
        }
        if (h == 1) {
                cout << 0 << '\n';
        } else if (h == 2) {
                int ans0 = 0, ans1 = 0;
                rep(i, w) {
                        if (i % 2 == 0) {
                                ans0 += s[0][i] ^ s[1][i];
                        } else {
                                ans0 += !(s[0][i] ^ s[1][i]);
                        }
                }
                rep(i, w) {
                        if (i % 2 != 0) {
                                ans1 += s[0][i] ^ s[1][i];
                        } else {
                                ans1 += !(s[0][i] ^ s[1][i]);
                        }
                }
                cout << min(ans0, ans1) << '\n';
        } else {
                vector<vector<long long>> dp(w + 1, vector<long long> (8, 1e9));
                rep(i, 8) {
                        dp[0][i] = 0;
                }
                rep(i, w) {
                        rep(k, 8) {
                                rep(j, 8) {
                                        auto get = [&](int num, int p) {
                                                return (num >> p) & 1;
                                        };
                                        int x = get(j, 0) + get(j, 1) + get(k, 0) + get(k, 1);
                                        int y = get(j, 1) + get(j, 2) + get(k, 1) + get(k, 2);
                                        if (x % 2 == 0 || y % 2 == 0) continue;
                                        int d = 0;
                                        rep(l, 3) {
                                                int r = get(k, l);
                                                d += r != s[l][i];
                                        }
                                        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + d);
                                }
                        }
                }
                long long ans = 1e9;
                rep(i, 8) {
                        ans = min(ans, dp[w][i]);
                }
                cout << ans << '\n';
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
