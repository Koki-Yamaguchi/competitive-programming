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
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        vector<int> y(n), x(n);
        rep(i, n) {
                cin >> y[i];
        }
        rep(i, n) {
                cin >> x[i];
        }
        rep(i, n) {
                p[i] = make_pair(y[i], x[i]);
        }
        sort(all(p));
        int prevy = 1, prevx = 1;
        ll ans = 0;
        rep(i, n) {
                int tot = p[i].first - prevy;
                int right = p[i].second - prevx;
                assert(right >= 0);
                int left = tot - right;
                int par = (prevy + prevx & 1);
                if (left == 0) {
                        if (par) {
                                // nothing
                        } else {
                                ans += right;
                        }
                } else {
                        ans += (left + par) / 2;
                }
                prevy = p[i].first;
                prevx = p[i].second;
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
