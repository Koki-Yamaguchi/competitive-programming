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
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<pair<int, int>> v;
        rep(i, n) {
                if (i && v.back().first == a[i]) {
                        v.back().second ++;
                } else {
                        v.emplace_back(a[i], 1);
                }
        }
        int l0 = -1, l1 = -1;
        int ans = 0;
        rep(i, v.size()) {
                auto [val, cnt] = v[i];
                if (cnt == 1) {
                        if (i + 1 < v.size()) {
                                auto [nxtval, _] = v[i + 1];
                                if (nxtval == l0 && val != l0) {
                                        ans ++;
                                        l0 = val;
                                } else if (nxtval == l1 && val != l1) {
                                        ans ++;
                                        l1 = val;
                                } else {
                                        if (val != l0) {
                                                ans ++;
                                                l0 = val;
                                        } else if (val != l1) {
                                                ans ++;
                                                l1 = val;
                                        }
                                }
                        } else {
                                ans ++;
                        }
                } else {
                        if (l0 != val) {
                                ans ++;
                                l0 = val;
                        }
                        if (l1 != val) {
                                ans ++;
                                l1 = val;
                        }
                }
        }
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
