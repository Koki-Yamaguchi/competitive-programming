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
        ll a, b, k;
        cin >> a >> b >> k;
        vector<ll> as(k), bs(k);
        rep(i, k) {
                cin >> as[i];
        }
        rep(i, k) {
                cin >> bs[i];
        }
        map<ll, ll> cnta, cntb;
        rep(i, k) {
                cnta[as[i]] ++;
                cntb[bs[i]] ++;
        }
        ll cnt0 = 0;
        for (auto it : cnta) {
                cnt0 += it.second * (it.second - 1) / 2;
        }
        ll cnt1 = 0;
        for (auto it : cntb) {
                cnt1 += it.second * (it.second - 1) / 2;
        }
        ll ans = k * (k - 1) / 2 - cnt0 - cnt1;
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
