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
        vector<vector<int>> a(2, vector<int> (n));
        rep(i, 2) {
                string s;
                cin >> s;
                rep(j, n) {
                        int b = s[j] - '0';
                        if (b <= 2) {
                                a[i][j] = 0;
                        } else {
                                a[i][j] = 1;
                        }
                }
        }
        vector<vector<bool>> to_left(2, vector<bool> (n + 1));
        to_left[0][0] = true;
        for (int i = 1; i <= n; i ++) {
                int aidx = i - 1;
                rep(j, 2) {
                        if (to_left[j][i - 1]) {
                                if (a[j][aidx] == 0) {
                                        to_left[j][i] = true;
                                }
                                if (a[j][aidx] == 1 && a[1 - j][aidx] == 1) {
                                        to_left[1 - j][i] = true;
                                }
                        }
                }
        }
        cout << (to_left[1][n] ? "YES\n" : "NO\n");
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
