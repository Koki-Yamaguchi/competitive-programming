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

const ll MOD = 1e9 + 7;

void solve(vector<ll> &fact) {
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(p, 40) {
                bool all = true;
                rep(i, n) {
                        all = all && ((a[i] >> p) & 1);
                }
                if (all) {
                        rep(i, n) {
                                a[i] -= (1 << p);
                        }
                }
        }
        int zc = 0;
        rep(i, n) {
                zc += (a[i] == 0);
        }
        if (zc < 2) {
                cout << 0 << '\n';
                return;
        }
        ll ans = (ll) zc * (zc - 1) % MOD;
        (ans *= fact[n - 2]) %= MOD;
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;
        const int ma = 200005;
        vector<ll> fact(ma);
        fact[0] = 1, fact[1] = 1;
        for (int i = 2; i < ma; i ++) {
                (fact[i] = fact[i - 1] * i) %= MOD;
        }
        while (t --) {
                solve(fact);
        }
        return 0;
}
