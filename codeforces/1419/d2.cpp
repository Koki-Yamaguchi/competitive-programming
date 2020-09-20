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
        if (n <= 2) {
                cout << 0 << '\n';
                rep(i, n) {
                        cout << a[i] << " ";
                }
                cout << '\n';
                return;
        }
        sort(a.begin(), a.end());
        vector<int> c, h;
        rep(i, n / 2) {
                c.push_back(a[i]);
        }
        for (int i = n / 2; i < n; i ++) {
                h.push_back(a[i]);
        }
        vector<int> ans;
        rep(i, c.size()) {
                ans.push_back(h[i]);
                ans.push_back(c[i]);
                if (i == (int) c.size() - 1 && h.size() > c.size()) {
                        ans.push_back(h[i + 1]);
                }
        }
        int cnt = 0;
        rep(i, ans.size()) {
                if (i > 0 && i < (int) ans.size() - 1) {
                        cnt += (ans[i - 1] > ans[i] && ans[i] < ans[i + 1]);
                }
        }
        cout << cnt << '\n';
        rep(i, ans.size()) {
                cout << ans[i] << " ";
        }
        cout << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        t = 1;
        // cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
