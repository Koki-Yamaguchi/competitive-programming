#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(10);
        rep(i, n) {
                cnt[s[i] - '0'] ++;
        }
        int ans = n + 100;
        rep(i, 10) {
                ans = min(ans, n - cnt[i]);
        }
        rep(a, 10) {
                rep(b, 10) {
                        int c = 0;
                        bool aa = true;
                        rep(i, n) {
                                if (aa) {
                                        if (s[i] - '0' == a) {
                                                aa = false;
                                                c ++;
                                        }
                                } else {
                                        if (s[i] - '0' == b) {
                                                aa = true;
                                                c ++;
                                        }
                                }
                        }
                        if (!aa) c --;
                        ans = min(ans, n - c);
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
