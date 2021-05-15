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
        /*
        for (int n = 2; n <= 25; n ++) {
                dump(n);
                vector<int> res;
                vector<int> a(n);
                rep(i, n) {
                        a[i] = i + 1;
                }
                int ma = 1;
                for (int s = 1; s <= (1 << n); s ++) {
                        int prod = 1;
                        rep(i, n) {
                                if ((s >> i) & 1) {
                                        (prod *= a[i]) %= n;
                                }
                        }
                        if (prod == 1) {
                                int c = __builtin_popcount(s);
                                chmax(ma, c);
                        }
                }
                for (int s = 1; s <= (1 << n); s ++) {
                        ll prod = 1;
                        rep(i, n) {
                                if ((s >> i) & 1) {
                                        (prod *= a[i]) %= n;
                                }
                        }
                        if (prod == 1) {
                                int c = __builtin_popcount(s);
                                if (c == ma) {
                                        vector<int> r;
                                        rep(i, n) {
                                                if ((s >> i) & 1) {
                                                        r.push_back(a[i]);
                                                }
                                        }
                                        res = r;
                                        break;
                                }
                        }
                }
                */
                int n;
                cin >> n;
                ll prod = 1;
                vector<int> ans = {1};
                for (int val = 2; val <= n - 2; val ++) {
                        if (gcd(val, n) == 1) {
                                ans.push_back(val);
                                (prod *= val) %= n;
                        }
                }
                if (prod != 1) {
                        (prod *= n - 1) %= n;
                        ans.push_back(n - 1);
                }
                assert(prod == 1);
                cout << ans.size() << '\n';
                cout << ans << '\n';
                /*
                dump(res);
                dump(ans);
                assert(ans == res);
        }
        */
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
