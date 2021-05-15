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
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        set<string> ss;
        rep(i, n) {
                for (int j = i + 1; j <= n; j ++) {
                        ss.insert(s.substr(i, j - i));
                }
        }
        int ans = 0;
        rep(i, m) {
                for (int j = i + 1; j <= m; j ++) {
                        if (ss.count(t.substr(i, j - i)) > 0) {
                                ans = max(ans, j - i);
                        }
                }
        }
        cout << n + m - 2 * ans << '\n';
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
