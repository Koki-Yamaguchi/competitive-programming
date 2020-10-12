#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        string s;
        cin >> s;
        int n = s.size();
        string ans;
        bool a = false, b = false;
        rep(i, n) {
                a = a || (s[i] == '0');
                b = b || (s[i] == '1');
        }
        if (!a || !b) {
                cout << s << '\n';
                return;
        }
        rep(i, n) {
                ans.push_back(s[i]);
                if (i < n - 1 && s[i] == s[i + 1]) {
                        if (s[i] == '0') {
                                ans.push_back('1');
                        } else {
                                ans.push_back('0');
                        }
                }
        }
        if (ans[0] == ans.back()) {
                ans.push_back('0' ^ '1' ^ ans.back());
        }
        cout << ans << '\n';
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
