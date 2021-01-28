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

const int MOD = 1e9 + 7;

long long ModPow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % MOD;
                x = x * x % MOD;
                n >>= 1;
        }
        return res;
}

void solve() {
        int n;
        ll p;
        cin >> n >> p;
        vector<ll> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        if (p == 1) {
                cout << (n & 1) << '\n';
                return;
        }
        sort(rall(a));
        ll ans = 0;
        ll exact = 0;
        bool rest_sub = false;
        rep(i, n) {
                if (rest_sub) {
                        (ans += MOD - ModPow(p, a[i])) %= MOD;
                        continue;
                }
                if (ans == 0 && exact == 0) {
                        (ans += ModPow(p, a[i])) %= MOD;
                        exact = 1;
                } else {
                        (ans += MOD - ModPow(p, a[i])) %= MOD;
                        assert(i > 0);
                        ll d = a[i - 1] - a[i];
                        // p > 1
                        while (d --) {
                                exact *= p;
                                if (exact > n) {
                                        rest_sub = true;
                                        break;
                                }
                        }
                        exact -= 1;
                }
        }
        cout << ans << '\n';
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
