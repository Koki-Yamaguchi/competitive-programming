#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> ostream& operator << (ostream& os, const set<T> &p) { os << "{"; for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << *it; } os << "}"; return os; }
template<typename T, typename U> ostream& operator << (ostream& os, const map<T, U> &p) { for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << "{" << (*it).first << ": " << (*it).second << "}"; } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<int> zi, oi;
        rep(i, n) {
                if (a[i] == 0) {
                        zi.push_back(i);
                } else {
                        oi.push_back(i);
                }
        }
        const int inf = 1e9;
        vector<vector<int>> dp(oi.size() + 1, vector<int> (zi.size() + 1, inf));
        rep(i, zi.size() + 1) {
                dp[0][i] = 0;
        }
        rep(i, oi.size()) {
                rep(j, zi.size()) {
                        int d = abs(oi[i] - zi[j]);
                        chmin(dp[i + 1][j + 1], dp[i + 1][j]);
                        chmin(dp[i + 1][j + 1], dp[i][j] + d);
                }
        }
        int ans = inf;
        rep(i, zi.size() + 1) {
                chmin(ans, dp[oi.size()][i]);
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
