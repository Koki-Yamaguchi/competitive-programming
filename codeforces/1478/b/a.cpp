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
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int x = d * 10;
        rep(i, n) {
                if (a[i] >= x) {
                        cout << "YES\n";
                } else {
                        vector<bool> can(100);
                        can[0] = true;
                        rep(i, 10) {
                                int v = 10 * i + d;
                                rep(j, 10) if (j) {
                                        int vvv = v * j;
                                        rep(k, 100) {
                                                if (can[k] && k + vvv < 100) {
                                                        can[k + vvv] = true;
                                                }
                                        }
                                }
                        }
                        if (can[a[i]]) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                }
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
