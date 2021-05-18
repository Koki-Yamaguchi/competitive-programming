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

const int MOD = 998244353;

long long mod_pow(long long x, long long n, long long m) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % m;
                x = x * x % m;
                n >>= 1;
        }
        return res;
}

void solve() {
        int h, w;
        cin >> h >> w;
        vector<string> t(h);
        rep(i, h) {
                cin >> t[i];
        }
        int hc = 0;
        rep(i, h) {
                rep(j, w) {
                        hc += (t[i][j] == 'o');
                }
        }
        ll ans = 0;

        auto calc = [&](const vector<string> &s) {
                rep(i, h) {
                        vector<ll> dp(w), leftdp(w);
                        int curhc = 0;
                        rep(j, w - 1) {
                                if (s[i][j] == '*') {
                                        curhc = 0;
                                }
                                if (s[i][j] != 'o' || s[i][j + 1] != 'o') {
                                        continue;
                                }
                                if (j == 0 || s[i][j - 1] == '*') {
                                        (dp[j] += mod_pow(2, hc - 2, MOD)) %= MOD; // wall
                                } else {
                                        (dp[j] += mod_pow(2, hc - 1 - 2, MOD)) %= MOD; // different color
                                }
                                (dp[j] += (j >= 2 ? leftdp[j - 2] : 0) * mod_pow(2, hc - curhc - 2, MOD)) %= MOD;
                                (ans += dp[j]) %= MOD;
                                (leftdp[j] = (j >= 2 ? leftdp[j - 2] : 0) + mod_pow(2, curhc - 1, MOD)) %= MOD;

                                curhc ++;
                        }
                }
        };
        calc(t);
        vector<string> tt(w);
        rep(i, w) {
                string p;
                rep(j, h) {
                        p.push_back(t[j][i]);
                }
                tt[i] = p;
        }
        swap(h, w);
        calc(tt);
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
