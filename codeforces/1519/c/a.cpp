#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n;
        cin >> n;
        vector<int> u(n), s(n);
        rep(i, n) {
                cin >> u[i];
                u[i] --;
        }
        rep(i, n) {
                cin >> s[i];
        }
        vector<vector<int>> grp(n);
        rep(i, n) {
                grp[u[i]].push_back(s[i]);
        }
        rep(i, n) {
                sort(rall(grp[i]));
        }
        sort(all(grp), [](const auto &a, const auto &b) {
                return a.size() > b.size();
        });
        vector<int> sz(n);
        vector<vector<int>> dp(n);
        rep(i, n) {
                sz[i] = - grp[i].size();
                dp[i].resize(grp[i].size());
        }
        rep(i, n) {
                rep(j, grp[i].size()) {
                        dp[i][j] = grp[i][j];
                        if (i > 0) dp[i][j] += dp[i - 1][j];
                        if (j > 0) dp[i][j] += dp[i][j - 1];
                        if (i > 0 && j > 0) {
                                dp[i][j] -= dp[i - 1][j - 1];
                        }
                }
        }
        rep(i, n) {
                dump(dp[i]);
        }
        vector<long long> ans(n, 0);
        for (int k = 1; k <= n; k ++) {
                int r = upper_bound(all(sz), -k) - sz.begin();
                if (r == 0) {
                        break;
                }
                ans[k - 1] = dp[r - 1][k - 1];
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
