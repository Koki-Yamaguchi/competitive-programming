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
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        vector<pair<int, int>> tmp;
        rep(i, n) {
                if (i && tmp.back().first == a[i]) {
                        tmp.back().second ++;
                } else {
                        tmp.emplace_back(a[i], 1);
                }
        }
        vector<int> v;
        rep(i, tmp.size()) {
                v.push_back(tmp[i].first);
        }
        n = v.size();
        const int inf = 1e9 + 5;
        vector<vector<int>> dp(n, vector<int> (n, inf)); // dp[i][a] := keep (a, v[i]) at index i
        dp[1][v[0]] = 2;
        dump(v);
        rep(i, n) if (i >= 2) {
                for (int j = 0; j < n; j ++) {
                        if (dp[i - 1][j] != inf) {
                                if (j == v[i]) {
                                        chmin(dp[i][v[i]], dp[i - 1][j]);
                                }
                                chmin(dp[i][j], dp[i - 1][j] + 1);
                                chmin(dp[i][v[i - 1]], dp[i - 1][j] + 1);
                        }
                }
                dump(dp[i]);
        }
        int ans = *min_element(all(dp[n - 1]));
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
