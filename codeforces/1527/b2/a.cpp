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

/*
void solve_adhoc() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool pal = true;
        rep(i, n / 2) {
                int j = n - i - 1;
                if (s[i] != s[j]) {
                        pal = false;
                        break;
                }
        }
        auto bob = []() {
                cout << "BOB" << '\n';
        };
        auto alice = []() {
                cout << "ALICE" << '\n';
        };
        auto draw = []() {
                cout << "DRAW" << '\n';
        };
        if (pal) {
                int c = 0;
                rep(i, n / 2) {
                        c += (s[i] == '0');
                }
                // first takes center
                if ((n & 1) && s[n / 2] == '0') {
                        if (c > 0) {
                                alice();
                        } else {
                                bob();
                        }
                } else {
                        bob();
                }
                return;
        }
        int diff = 0;
        rep(i, n / 2) {
                int j = n - i - 1;
                diff += (s[i] != s[j]);
        }
        assert(diff >= 1);
        int zero = 0;
        bool center = false;
        rep(i, n) {
                if ((n & 1) && i == n / 2 && s[i] == '0') {
                        center = true;
                        continue;
                }
                zero += (s[i] == '0');
        }
        zero -= diff;
        assert(zero % 2 == 0);
        zero /= 2;
        if (center) {
                if (diff == 1 && zero == 0) {
                        draw();
                } else {
                        alice();
                }
        } else {
                alice();
        }
}
*/

const int MA = 501;
const int inf = 1e9;
int dp[MA][MA][2][2];
int calc(int c00, int c01, bool is_center_0, bool is_prev_rev) {
        int &ref = dp[c00][c01][is_center_0][is_prev_rev];
        if (ref != inf) {
                return ref;
        }
        if (c00 == 0 && c01 == 0 && (not is_center_0)) {
                ref = 0;
                return ref;
        }
        if (c00 > 0) {
                chmin(ref, 1 - calc(c00 - 1, c01 + 1, is_center_0, false));
        }
        if (c01 > 0) {
                chmin(ref, 1 - calc(c00, c01 - 1, is_center_0, false));
        }
        if (is_center_0) {
                chmin(ref, 1 - calc(c00, c01, false, false));
        }
        if ((not is_prev_rev) && c01 != 0) {
                chmin(ref, - calc(c00, c01, is_center_0, true));
        }
        return ref;
}

void solve_dp() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c00 = 0;
        rep(i, n / 2) {
                int j = n - i - 1;
                c00 += (s[i] == '0' && s[i] == s[j]);
        }
        int c01 = 0;
        rep(i, n / 2) {
                int j = n - i - 1;
                c01 += (s[i] != s[j]);
        }
        bool is_center_0 = (n & 1) && (s[n / 2] == '0');
        int ans = calc(c00, c01, is_center_0, false);
        if (ans < 0) {
                cout << "ALICE\n";
        } else if (ans == 0) {
                cout << "DRAW\n";
        } else {
                cout << "BOB\n";
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;

        rep(i, MA) rep(j, MA) rep(k, 2) rep(l, 2) dp[i][j][k][l] = inf;

        while (t --) {
                solve_dp();
        }
        return 0;
}
