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
        if (n == 1) {
                cout << 1 << '\n';
                return;
        } else if (n == 2) {
                cout << -1 << '\n';
                return;
        }
        int c = 1;
        vector<vector<int>> ans(n, vector<int> (n));
        rep(i, n) {
                int st = (i & 1);
                for (int j = st; j < n; j += 2) {
                        ans[i][j] = c ++;
                }
        }
        rep(i, n) {
                int st = (i % 2 == 0);
                for (int j = st; j < n; j += 2) {
                        ans[i][j] = c ++;
                }
        }
        rep(i, n) {
                cout << ans[i] << '\n';
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
