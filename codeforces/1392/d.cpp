#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> nxt(n);
        rep(i, n) {
                if (s[i] == 'L') {
                        nxt[i] = ((i - 1) + n) % n;
                } else {
                        nxt[i] = (i + 1) % n;
                }
        }
        vector<int> in(n);
        rep(i, n) {
                in[nxt[i]] ++;
        }
        int cur = 0;
        vector<bool> used(n);
        while (true) {
                if (used[cur]) break;
                used[cur] = true;
                cur = nxt[cur];
        }
        bool loop = true;
        rep(i, n) {
                if (!used[i]) {
                        loop = false;
                }
        }
        loop = loop & (cur == 0);
        if (loop) {
                cout << (n + 2) / 3 << '\n';
        } else {
                vector<bool> used(n);
                int len = 0;
                function<void (int, int)> dfs = [&](int u, int prev) {
                        int v = nxt[u];
                        if (v == prev) return;
                        len ++;
                        dfs(v, u);
                };
                int ans = 0;
                rep(i, n) {
                        len = 0;
                        if (in[i] == 0 && !used[i]) {
                                dfs(i, -1);
                        }
                        len --;
                        ans += (len + 1) / 3;
                }
                cout << ans << '\n';
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
