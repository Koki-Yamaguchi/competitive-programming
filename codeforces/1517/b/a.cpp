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
        vector<vector<int>> a(n, vector<int> (m));
        vector<pair<int, pair<int, int>>> v;
        rep(i, n) {
                rep(j, m) {
                        cin >> a[i][j];
                        v.emplace_back(a[i][j], make_pair(i, j));
                }
        }
        sort(all(v));
        vector<vector<bool>> good(n, vector<bool> (m));
        rep(i, m) {
                auto [y, x] = v[i].second;
                good[y][x] = true;
        }
        vector<vector<bool>> used(n, vector<bool> (m));
        vector<vector<int>> ans(n, vector<int> (m));
        rep(r, m) {
                // calc for runner r
                bool ok = false;
                rep(y, n) {
                        if (ok) {
                                rep(x, m) {
                                        if (not used[y][x] && not good[y][x]) {
                                                used[y][x] = true;
                                                ans[y][r] = a[y][x];
                                                break;
                                        }
                                }
                        } else {
                                rep(x, m) {
                                        if (not used[y][x] && good[y][x]) {
                                                used[y][x] = true;
                                                ans[y][r] = a[y][x];
                                                ok = true;
                                                break;
                                        }
                                }
                                if (not ok) {
                                        rep(x, m) {
                                                if (not used[y][x]) {
                                                        used[y][x] = true;
                                                        ans[y][r] = a[y][x];
                                                        break;
                                                }
                                        }
                                }
                        }
                }
        }
        rep(i, n) {
                rep(j, m) {
                        cout << ans[i][j] << " ";
                }
                cout << '\n';
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
