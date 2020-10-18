#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        // 11 00
        {
                vector<pair<int, int>> ans;
                if (s[0][1] == '0') ans.emplace_back(0, 1);
                if (s[1][0] == '0') ans.emplace_back(1, 0);
                if (s[n - 1][n - 2] == '1') ans.emplace_back(n - 1, n - 2);
                if (s[n - 2][n - 1] == '1') ans.emplace_back(n - 2, n - 1);
                if (ans.size() <= 2) {
                        cout << ans.size() << '\n';
                        rep(i, ans.size()) {
                                cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
                        }
                        return;
                }
        }
        // 00 11
        {
                vector<pair<int, int>> ans;
                if (s[0][1] == '1') ans.emplace_back(0, 1);
                if (s[1][0] == '1') ans.emplace_back(1, 0);
                if (s[n - 1][n - 2] == '0') ans.emplace_back(n - 1, n - 2);
                if (s[n - 2][n - 1] == '0') ans.emplace_back(n - 2, n - 1);
                if (ans.size() <= 2) {
                        cout << ans.size() << '\n';
                        rep(i, ans.size()) {
                                cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
                        }
                        return;
                }
        }
        assert(false);
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
