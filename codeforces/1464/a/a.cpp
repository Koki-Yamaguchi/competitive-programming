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
        int mv = 0;
        map<int, vector<int>> g;
        rep(i, m) {
                int y, x;
                cin >> y >> x;
                y --, x --;
                if (y == x) {
                        continue;
                }
                mv ++;
                int w = y * n + x;
                int u = y * n + y;
                int v = x * n + x;
                g[u].push_back(w);
                g[w].push_back(u);
                g[v].push_back(w);
                g[w].push_back(v);
        }
        map<int, bool> used;
        bool path = false;
        auto dfs = [&](auto self, int u) -> void {
                if (g[u].size() == 1) {
                        path = true;
                }
                used[u] = true;
                for (auto v : g[u]) if (not used[v]) {
                        self(self, v);
                }
        };
        int con = 0;
        int pathc = 0;
        for (auto it : g) {
                int u = it.first;
                auto g = it.second;
                path = false;
                if (not used[u]) {
                        con ++;
                        dfs(dfs, u);
                }
                if (path) {
                        pathc ++;
                }
        }
        cout << mv + (con - pathc) << '\n';
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
