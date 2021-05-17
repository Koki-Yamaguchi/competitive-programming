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

const ll MOD = 998244353;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        rep(i, n) {
                rep(j, m) {
                        cin >> a[i][j];
                }
        }
        ll ans = 0;
        ll factn = 1;
        rep(i, n) {
                (factn *= (i + 1)) %= MOD;
        }
        ll invfactn = mod_pow(factn, MOD - 2, MOD);
        rep(j, m) {
                vector<int> v;
                rep(i, n) {
                        v.push_back(a[i][j] - 1);
                }
                sort(all(v));
                ll res = 1;
                rep(i, n) {
                        (res *= max(0, v[i] - i)) %= MOD;
                }
                (ans += (factn + MOD - res)) %= MOD;
        }
        (ans *= invfactn) %= MOD;
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
