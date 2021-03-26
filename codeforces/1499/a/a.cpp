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

bool ok(int k1, int k2, int w) {
        int can = k1 / 2 + k2 / 2;
        if (can >= w) {
                return true;
        }
        if (k1 > 0 && k2 > 0) {
                can = (k1 - 1) / 2 + (k2 - 1) / 2 + 1;
                if (can >= w) {
                        return true;
                }
        }
        return false;
}

void solve() {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        int kk1 = n - k1;
        int kk2 = n - k2;
        cout << (ok(k1, k2, w) && ok(kk1, kk2, b) ? "YES\n" : "NO\n");
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
