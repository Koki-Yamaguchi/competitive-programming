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
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<int>> a(n, vector<int> (m));
        rep(i, n) {
                rep(j, m) {
                        cin >> a[i][j];
                }
        }
        const int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
        const ll inf = 1e18 + 5;
        ll ans = inf;
        vector<ll> from;
        {
                queue<tuple<int, int, ll>> que;
                vector<vector<bool>> used(n, vector<bool> (m));
                que.push({0, 0, 0});
                used[0][0] = true;
                while (not que.empty()) {
                        auto [y, x, step] = que.front();
                        que.pop();
                        if (a[y][x] != 0) {
                                from.push_back(a[y][x] + step * w);
                        }
                        if (y == n - 1 && x == m - 1) {
                                ans = min(ans, step * w);
                        }
                        rep(d, 4) {
                                int ny = y + dy[d];
                                int nx = x + dx[d];
                                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                                        continue;
                                }
                                if (a[ny][nx] == -1) {
                                        continue;
                                }
                                if (used[ny][nx]) {
                                        continue;
                                }
                                used[ny][nx] = true;
                                que.push({ny, nx, step + 1});
                        }
                }
        }
        vector<ll> to;
        {
                queue<tuple<int, int, ll>> que;
                vector<vector<bool>> used(n, vector<bool> (m));
                que.push({n - 1, m - 1, 0});
                used[n - 1][m - 1] = true;
                while (not que.empty()) {
                        auto [y, x, step] = que.front();
                        que.pop();
                        if (a[y][x] != 0) {
                                to.push_back(a[y][x] + step * w);
                        }
                        rep(d, 4) {
                                int ny = y + dy[d];
                                int nx = x + dx[d];
                                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                                        continue;
                                }
                                if (a[ny][nx] == -1) {
                                        continue;
                                }
                                if (used[ny][nx]) {
                                        continue;
                                }
                                used[ny][nx] = true;
                                que.push({ny, nx, step + 1});
                        }
                }
        }
        sort(all(from));
        sort(all(to));
        if (from.size() && to.size()) {
                ans = min(ans, from[0] + to[0]);
        }
        if (ans != inf) {
                cout << ans << '\n';
        } else {
                cout << -1 << '\n';
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
