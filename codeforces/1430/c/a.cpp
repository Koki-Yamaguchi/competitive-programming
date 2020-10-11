#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                a[i] = i + 1;
        }
        int cur = a[n - 1];
        vector<pair<int, int>> ans;
        for (int i = n - 2; i >= 0; i --) {
                ans.emplace_back(cur, a[i]);
                cur = (cur + a[i] + 1) / 2;
        }
        cout << cur << '\n';
        rep(i, ans.size()) {
                cout << ans[i].first << " " << ans[i].second << '\n';
        }
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
