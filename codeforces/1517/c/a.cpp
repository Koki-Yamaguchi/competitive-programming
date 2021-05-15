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
        vector<vector<int>> ans(n, vector<int> (n, -1));
        rep(i, n) {
                int y = i;
                int x = i;
                int v = a[i];
                ans[i][i] = v;
                int c = v - 1;
                while (c --) {
                        if (ans[y][x - 1] == -1) {
                                x --;
                                ans[y][x] = v;
                                continue;
                        }
                        assert(ans[y + 1][x] == -1);
                        y ++;
                        ans[y][x] = v;
                }
        }
        rep(i, n) {
                rep(j, i + 1) {
                        cout << ans[i][j] << ' ';
                }
                cout << '\n';
        }
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
