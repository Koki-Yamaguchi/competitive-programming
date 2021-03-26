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
        int n; cin >> n;
        vector<string> s(n), t(n);
        rep(i, n) {
                cin >> s[i];
        }
        rep(i, n) {
                cin >> t[i];
        }
        bool ok = true;
        rep(i, n - 1) {
                rep(j, n - 1) {
                        int sc = 0, tc = 0;
                        for (int y = i; y <= i + 1; y ++) {
                                for (int x = j; x <= j + 1; x ++) {
                                        sc += (s[y][x] == '1');
                                        tc += (t[y][x] == '1');
                                }
                        }
                        if ((sc & 1) != (tc & 1)) {
                                ok = false;
                                break;
                        }
                }
        }
        cout << (ok ? "YES\n" : "NO\n");
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
