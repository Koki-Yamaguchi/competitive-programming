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
        vector<int> ans;
        for (int i = 0; i < n - 3; i += 4) {
                int c = 0;
                for (int j = i; j < i + 4; j ++) {
                        c += a[j];
                }
                if (c >= 3) {
                        ans.push_back(1);
                        ans.push_back(1);
                } else {
                        ans.push_back(0);
                        ans.push_back(0);
                }
        }
        if (n % 4 == 2) {
                if (a[n - 1] ^ a[n - 2]) {
                        ans.push_back(0);
                } else {
                        ans.push_back(a[n - 1]);
                        ans.push_back(a[n - 2]);
                }
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i] << " \n"[i == ans.size() - 1];
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
