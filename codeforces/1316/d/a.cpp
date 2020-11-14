#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p) {
        os << p.first << " " << p.second;
        return os;
}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

const char dir[4] = {'U', 'D', 'L', 'R'};
const char rdir[4] = {'D', 'U', 'R', 'L'};
const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void solve() {
        int n; cin >> n;
        vector<vector<pair<int, int>>> val(n, vector<pair<int, int>> (n));
        rep(i, n) {
                rep(j, n) {
                        int x, y;
                        cin >> y >> x;
                        if (x != -1) {
                                x --, y --;
                        }
                        val[i][j] = make_pair(y, x);
                }
        }
        vector<vector<char>> ans(n, vector<char> (n, '*'));
        rep(i, n) {
                rep(j, n) {
                        if (val[i][j].first == -1) {
                                bool f = false;
                                rep(d, 4) {
                                        int ii = i + dy[d];
                                        int jj = j + dx[d];
                                        if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                                        if (val[ii][jj].first == -1) {
                                                f = true;
                                                ans[i][j] = dir[d];
                                                break;
                                        }
                                }
                                if (!f) {
                                        cout << "INVALID" << '\n';
                                        return;
                                }
                        }
                }
        }
        vector<pair<int, int>> fins;
        rep(i, n) {
                rep(j, n) {
                        if (val[i][j] == make_pair(i, j)) {
                                fins.emplace_back(i, j);
                        }
                }
        }
        function<void (pair<int, int>, pair<int, int>, pair<int, int>)> dfs = [&](pair<int, int> u, pair<int, int> prev, pair<int, int> v) {
                int i = u.first;
                int j = u.second;
                rep(d, 4) {
                        int ii = i + dy[d];
                        int jj = j + dx[d];
                        if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                        if (prev == make_pair(ii, jj)) continue;
                        if (ans[ii][jj] != '*') continue;
                        if (val[ii][jj] != v) continue;
                        ans[ii][jj] = rdir[d];
                        dfs(make_pair(ii, jj), u, v);
                }
        };
        for (pair<int, int> fin : fins) {
                ans[fin.first][fin.second] = 'X';
                dfs(fin, make_pair(-1, -1), fin);
        }
        rep(i, n) {
                rep(j, n) {
                        if (ans[i][j] == '*') {
                                cout << "INVALID" << '\n';
                                return;
                        }
                }
        }
        cout << "VALID" << "\n";
        rep(i, n) {
                rep(j, n) {
                        cout << ans[i][j];
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
