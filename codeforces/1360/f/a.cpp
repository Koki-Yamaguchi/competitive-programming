#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        vector<string> cs;
        cs.push_back(s[0]);
        rep(i, m) {
                rep(j, 26) {
                        string t = s[0];
                        t[i] = 'a' + j;
                        cs.push_back(t);
                }
        }
        rep(i, cs.size()) {
                bool ok = true;
                rep(j, n) {
                        int dc = 0;
                        rep(k, m) {
                                dc += (cs[i][k] != s[j][k]);
                        }
                        if (dc > 1) {
                                ok = false;
                                break;
                        }
                }
                if (ok) {
                        cout << cs[i] << '\n';
                        return;
                }
        }
        cout << -1 << '\n';
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
