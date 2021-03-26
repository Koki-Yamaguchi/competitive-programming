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

const int N = 3;

void solve() {
        vector<int> n(N);
        rep(i, N) {
                cin >> n[i];
        }
        vector<vector<int>> a(N);
        vector<ll> ss(N);
        ll sum = 0;
        rep(i, N) {
                a[i].resize(n[i]);
                rep(j, n[i]) {
                        cin >> a[i][j];
                        sum += a[i][j];
                        ss[i] += a[i][j];
                }
        }
        rep(i, N) {
                sort(all(a[i]));
        }
        vector<int> fs = {a[0][0], a[1][0], a[2][0]};
        sort(all(fs));
        ll ans = sum - 2ll * (fs[0] + fs[1]);
        rep(i, N) {
                chmax(ans, sum - 2ll * ss[i]);
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
