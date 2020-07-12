#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> ans;
        for (int x = 1; x <= 2000; x ++) {
                vector<int> b(n);
                rep(i, n) {
                        b[i] = a[i] - x;
                }
                int r = 0;
                int cur = 0;
                long long res = 1;
                rep(i, n) {
                        while (cur < n && b[cur] <= i) {
                                cur ++;
                                r ++;
                        }
                        (res *= r) %= p;
                        r --;
                }
                if (res != 0) {
                        ans.push_back(x);
                }
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i] << " ";
        }
        cout << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t = 1;
        // cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
