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
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        int y0 = -1, x0, y1, x1;
        rep(i, n) {
                rep(j, n) {
                        if (s[i][j] == '*') {
                                if (y0 == -1) {
                                        y0 = i;
                                        x0 = j;
                                } else {
                                        y1 = i;
                                        x1 = j;
                                }
                        }
                }
        }
        if (y0 == y1) {
                s[(y0 + 1) % n][x0] = '*';
                s[(y0 + 1) % n][x1] = '*';
        } else if (x0 == x1) {
                s[y0][(x0 + 1) % n] = '*';
                s[y1][(x0 + 1) % n] = '*';
        } else {
                s[y0][x1] = '*';
                s[y1][x0] = '*';
        }
        rep(i, n) {
                cout << s[i] << '\n';
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
