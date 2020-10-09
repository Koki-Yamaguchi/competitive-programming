#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string ans;
        if (n1 || n2) {
                rep(i, n2 + 1) {
                        ans += "1";
                }
        }
        if (n0 || n1) {
                rep(i, n0 + 1) {
                        ans += "0";
                }
        }
        rep(i, n1 - 1) {
                ans += (ans.back() == '1' ? "0" : "1");
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
