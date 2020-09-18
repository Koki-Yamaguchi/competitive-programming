#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        string s = string(200, 'a');
        vector<string> ans;
        ans.push_back(s);
        rep(i, n) {
                string nxt = s;
                nxt[a[i]] = s[a[i]] != 'a' ? 'a' : 'b';
                ans.push_back(nxt);
                s = nxt;
        }
        rep(i, n + 1) {
                cout << ans[i] << '\n';
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
