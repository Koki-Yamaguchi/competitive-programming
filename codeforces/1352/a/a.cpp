#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        int b = 1;
        vector<int> ans;
        while (n) {
                if (n % 10 != 0) {
                        ans.push_back((n % 10) * b);
                }
                b *= 10;
                n /= 10;
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) cout << ans[i] << " ";
        cout << '\n';
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
