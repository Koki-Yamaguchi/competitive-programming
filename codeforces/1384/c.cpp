#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<set<int>> st(20);
        rep(i, n) {
                int a = s[i] - 'a';
                int b = t[i] - 'a';
                if (a > b) {
                        cout << -1 << '\n';
                        return;
                }
                st[a].insert(b);
        }
        int ans = 0;
        rep(i, 20) {
                bool f = true;
                int nxt = -1;
                for (int v : st[i]) {
                        if (v == i) {
                                continue;
                        }
                        if (f) {
                                f = false;
                                nxt = v;
                                ans ++;
                        } else {
                                st[nxt].insert(v);
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
