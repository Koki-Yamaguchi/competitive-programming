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

const ll MOD = 1e9 + 7;
ll dp[10][200005];

ll calc(int val, int m) {
        if (dp[val][m] != -1) {
                return dp[val][m];
        }
        if (m == 0) {
                dp[val][m] = 1;
                return dp[val][m];
        }
        if (val == 9) {
                (dp[val][m] = calc(1, m - 1) + calc(0, m - 1)) %= MOD;
        } else {
                dp[val][m] = calc(val + 1, m - 1);
        }
        return dp[val][m];
}

void solve() {
        string n;
        int m;
        cin >> n >> m;
        ll ans = 0;
        rep(i, n.size()) {
                int s = n[i] - '0';
                (ans += calc(s, m)) %= MOD;
        }
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;

        rep(i, 10) rep(j, 200005) dp[i][j] = -1;
        while (t --) {
                solve();
        }
        return 0;
}
