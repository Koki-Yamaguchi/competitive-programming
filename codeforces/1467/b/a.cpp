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

int calc_at_point(const vector<int> &a, int idx) {
        int n = a.size();
        if (idx > 0 && idx < n - 1) {
                if (a[idx - 1] > a[idx] && a[idx] < a[idx + 1]) {
                        return 1;
                }
                if (a[idx - 1] < a[idx] && a[idx] > a[idx + 1]) {
                        return 1;
                }
        }
        return 0;
};

int calc_at_range(const vector<int> &a, int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i ++) {
                res += calc_at_point(a, i);
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int s = calc_at_range(a, 0, n - 1);
        int ans = s;
        rep(i, n) {
                int o = a[i];
                for (int d = -1; d <= 1; d += 2) {
                        if (0 <= i + d && i + d < n) {
                                int t = s;
                                t -= calc_at_range(a, i - 1, i + 1);
                                a[i] = a[i + d];
                                t += calc_at_range(a, i - 1, i + 1);
                                a[i] = o;
                                ans = min(ans, t);
                        }
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
