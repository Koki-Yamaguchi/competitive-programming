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
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        vector<int> left(m), right(m);
        int sp = 0, tp = 0;
        while (true) {
                while (s[sp] != t[tp]) {
                        sp ++;
                        assert(sp < n);
                }
                left[tp] = sp;
                sp ++;
                tp ++;
                if (tp == m) {
                        break;
                }
        }
        sp = n - 1, tp = m - 1;
        while (true) {
                while (s[sp] != t[tp]) {
                        sp --;
                        assert(sp >= 0);
                }
                right[tp] = sp;
                sp --;
                tp --;
                if (tp == -1) {
                        break;
                }
        }
        int ans = 0;
        rep(i, m - 1) {
                ans = max(ans, right[i + 1] - left[i]);
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
