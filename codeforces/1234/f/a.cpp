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

#ifdef LOCAL
const int sz = 6;
#else
const int sz = 20;
#endif

void solve() {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> vals;
        vector<int> dp(1 << sz);
        rep(l, n) {
                vector<bool> used(sz);
                int mask = 0;
                int cnt = 0;
                for (int p = l; p < n; p ++) {
                        int c = s[p] - 'a';
                        if (used[c]) {
                                break;
                        }
                        used[c] = true;
                        mask |= (1 << c);
                        vals.push_back(mask);
                        dp[mask] = ++ cnt;
                }
        }
        vals.erase(unique(all(vals)), vals.end());
        rep(i, 1 << sz) {
                rep(j, sz) {
                        if ((i >> j) & 1) {
                                int sub = i ^ (1 << j);
                                chmax(dp[i], dp[sub]);
                        }
                }
        }
        int ans = 0;
        rep(i, vals.size()) {
                int rev = (1 << sz) - 1;
                ans = max(ans, dp[vals[i]] + dp[vals[i] ^ rev]);
        }
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
