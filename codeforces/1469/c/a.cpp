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
        ll n, k;
        cin >> n >> k;
        vector<ll> h(n);
        rep(i, n) {
                cin >> h[i];
        }
        ll mi = h[0], ma = h[0] + k - 1;
        rep(i, n - 1) {
                mi = max(mi, h[i]);
                ma = min(ma, h[i] + k - 1);
                if (mi > ma) {
                        cout << "NO\n";
                        return;
                }
                mi = mi - (k - 1);
                ma = ma + k - 1;
        }
        if (mi <= h.back() && h.back() <= ma) {
                cout << "YES\n";
        } else {
                cout << "NO\n";
        }
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
