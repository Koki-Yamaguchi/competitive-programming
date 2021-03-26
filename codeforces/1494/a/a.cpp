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
        string s;
        cin >> s;
        int n = s.size();
        rep(p, 1 << 3) {
                int a = ((p >> 0) & 1 ? 1 : -1);
                int b = ((p >> 1) & 1 ? 1 : -1);
                int c = ((p >> 2) & 1 ? 1 : -1);
                int res = 0;
                bool f = true;
                rep(i, n) {
                        if (s[i] == 'A') {
                                res += a;
                        } else if (s[i] == 'B') {
                                res += b;
                        } else {
                                res += c;
                        }
                        if (res < 0) {
                                f = false;
                                break;
                        }
                }
                if (f && res == 0) {
                        cout << "YES\n";
                        return;
                }
        }
        cout << "NO\n";
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
