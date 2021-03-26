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
        vector<int> s;
        rep(i, n) {
                bool f = true;
                if (i > 0 && a[i - 1] > a[i]) {
                        f = false;
                }
                if (i < n - 1 && a[i + 1] > a[i]) {
                        f = false;
                }
                if (not f) {
                        continue;
                }
                int left = 0, right = 0;
                for (int j = i - 1; j >= 0 && a[j] < a[j + 1]; j --) {
                        left ++;
                }
                for (int j = i + 1; j < n && a[j] < a[j - 1]; j ++) {
                        right ++;
                }
                s.push_back(left);
                s.push_back(right);
        }
        n = s.size();
        vector<int> lma(n), rma(n);
        lma[0] = s[0];
        rma[n - 1] = s[n - 1];
        rep(i, n) if (i) {
                lma[i] = max(lma[i - 1], s[i]);
        }
        for (int i = n - 2; i >= 0; i --) {
                rma[i] = max(rma[i + 1], s[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
                if (s[i] == s[i + 1] && (s[i] % 2 == 0)) {
                        int lmaa = i > 0 ? lma[i - 1] : -1;
                        int rmaa = i + 1 < n - 1 ? rma[i + 2] : -1;
                        if (lmaa < s[i] && rmaa < s[i]) {
                                ans ++;
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
