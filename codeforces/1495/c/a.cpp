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
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        rep(i, h) {
                cin >> s[i];
        }
        rep(x, w) {
                if (x % 3 == 1) {
                        rep(y, h) {
                                s[y][x] = 'X';
                        }
                }
        }
        rep(x, w) {
                if (x > 0 && x % 3 == 0) {
                        bool f = false;
                        rep(y, h) {
                                if (s[y][x] == 'X' || s[y][x - 1] == 'X') {
                                        s[y][x] = 'X';
                                        s[y][x - 1] = 'X';
                                        f = true;
                                        if (x != w - 1) {
                                                break;
                                        }
                                }
                        }
                        if (not f) {
                                s[0][x] = 'X';
                                s[0][x - 1] = 'X';
                        }
                }
        }
        rep(i, h) {
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
