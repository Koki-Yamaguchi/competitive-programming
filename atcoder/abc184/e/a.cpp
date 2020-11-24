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

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

void solve() {
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        rep(i, h) {
                cin >> s[i];
        }
        vector<vector<pair<int, int>>> to(26);
        int sy, sx, gy, gx;
        rep(i, h) {
                rep(j, w) {
                        if (s[i][j] == 'S') {
                                sy = i;
                                sx = j;
                        } else if (s[i][j] == 'G') {
                                gy = i;
                                gx = j;
                        } else if (0 <= s[i][j] - 'a' && s[i][j] - 'a' < 26) {
                                to[s[i][j] - 'a'].emplace_back(i, j);
                        }
                }
        }
        vector<vector<int>> dist(h, vector<int> (w, 1 << 30));
        queue<pair<int, int>> que;
        dist[sy][sx] = 0;
        que.push({sy, sx});
        vector<bool> used(26);
        while (!que.empty()) {
                auto p = que.front(); que.pop();
                int y = p.first;
                int x = p.second;
                rep(d, 4) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                        if (s[ny][nx] == '#') continue;
                        if (dist[ny][nx] == 1 << 30) {
                                dist[ny][nx] = dist[y][x] + 1;
                                que.push({ny, nx});
                        }
                }
                if (0 <= s[y][x] - 'a' && s[y][x] - 'a' < 26) {
                        if (not used[s[y][x] - 'a']) {
                                auto vs = to[s[y][x] - 'a'];
                                for (pair<int, int> v : vs) {
                                        int ny = v.first;
                                        int nx = v.second;
                                        if (ny == y && nx == x) continue;
                                        if (dist[ny][nx] == 1 << 30) {
                                                dist[ny][nx] = dist[y][x] + 1;
                                                que.push({ny, nx});
                                        }
                                }
                        }
                        used[s[y][x] - 'a'] = true;
                }
        }
        if (dist[gy][gx] == 1 << 30) {
                cout << -1 << '\n';
        } else {
                cout << dist[gy][gx] << '\n';
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
