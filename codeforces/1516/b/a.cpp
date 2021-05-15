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
        vector<int> acc(n);
        acc[0] = a[0];
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] ^ a[i];
        }
        bool ok = false;
        for (int i = 0; i < n - 1; i ++) {
                ok = ok || (acc[i] == (acc[n - 1] ^ acc[i]));
        }
        for (int i = 0; i < n - 2; i ++) {
                for (int j = i + 1; j < n - 1; j ++) {
                        ok = ok || (acc[i] == (acc[j] ^ acc[i]) && acc[i] == (acc[n - 1] ^ acc[j]));
                }
        }
        cout << (ok ? "YES\n" : "NO\n");
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
