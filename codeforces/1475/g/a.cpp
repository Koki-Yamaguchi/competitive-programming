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
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        map<int, int> res;
        rep(i, n) {
                vector<int> divs;
                for (int d = 1; d * d <= a[i]; d ++) {
                        if (a[i] % d == 0) {
                                divs.push_back(d);
                                if (d != a[i] / d) {
                                        divs.push_back(a[i] / d);
                                }
                        }
                }
                int ma = 0;
                for (auto div : divs) {
                        ma = max(ma, res[div] + 1);
                }
                res[a[i]] = ma;
        }
        int ans = 0;
        for (auto it : res) {
                ans = max(ans, it.second);
        }
        cout << n - ans << '\n';
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
