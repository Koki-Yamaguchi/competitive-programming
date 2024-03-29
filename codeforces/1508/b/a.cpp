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

void solve(const int man, const vector<ll> &dp) {
        int n;
        ll k;
        cin >> n >> k;
        if (n <= man && dp[n] < k) {
                cout << -1 << '\n';
                return;
        }
        dump(dp);
        vector<int> ans(n);
        rep(i, n) {
                // TODO greedily count the number
        }
        cout << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;

        const int man = 100;
        const ll inf = 1e18 + 10;
        vector<ll> dpf(man + 1), dpb(man + 1);
        dpf[0] = 1, dpf[1] = 1;
        dpb[0] = 1, dpb[1] = 0;
        for (int i = 2; i < man + 1; i ++) {
                dpf[i] = dpf[i - 1] + dpb[i - 1];
                dpb[i] = dpb[i - 1] + dpf[i - 2];
                if (dpf[i] > inf) {
                        dpf[i] = inf;
                }
                if (dpb[i] > inf) {
                        dpb[i] = inf;
                }
        }
        vector<ll> dp(man + 1);
        rep(i, man + 1) {
                dp[i] = dpf[i] + dpb[i];
        }
        while (t --) {
                solve(man, dp);
        }
        return 0;
}
