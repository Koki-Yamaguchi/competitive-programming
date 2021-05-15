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
        int a, b;
        cin >> a >> b;
        int n = a + b;
        string s;
        cin >> s;
        rep(i, n) {
                if (s[i] == '0') {
                        if (s[n - i - 1] == '1') {
                                cout << -1 << '\n';
                                return;
                        }
                        s[n - i - 1] = '0';
                } else if (s[i] == '1') {
                        if (s[n - i - 1] == '0') {
                                cout << -1 << '\n';
                                return;
                        }
                        s[n - i - 1] = '1';
                }
        }
        rep(i, n) {
                if (s[i] == '0') {
                        a --;
                } else if (s[i] == '1') {
                        b --;
                }
        }
        if (a < 0 || b < 0) {
                cout << -1 << '\n';
                return;
        }
        rep(i, n) {
                if (s[i] == '?') {
                        if (i != n - i - 1) {
                                if (a >= 2) {
                                        a -= 2;
                                        s[i] = '0';
                                        s[n - i - 1] = '0';
                                } else if (b >= 2) {
                                        b -= 2;
                                        s[i] = '1';
                                        s[n - i - 1] = '1';
                                } else {
                                        cout << -1 << '\n';
                                        return;
                                }
                        } else {
                                if (a & 1) {
                                        a --;
                                        s[i] = '0';
                                } else if (b & 1) {
                                        b --;
                                        s[i] = '1';
                                } else {
                                        cout << -1 << '\n';
                                        return;
                                }
                        }
                }
        }
        cout << s << '\n';
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
