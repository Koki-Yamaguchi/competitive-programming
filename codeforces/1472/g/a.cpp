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

//unweighted graph
vector<int> Dijkstra(int start, const vector<vector<int>> &g) {
        int n = (int) g.size();
        vector<int> dist(n, 1 << 30);
        priority_queue<pair<int, int>> que;
        dist[start] = 0;
        que.push({0, start});
        while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int u = p.second;
                for (auto v : g[u]) {
                        if (dist[v] > dist[u] + 1) {
                                dist[v] = dist[u] + 1;
                                que.push({-dist[v], v});
                        }
                }
        }
        return dist;
}

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
        }
        auto dist = Dijkstra(0, g);
        const int inf = 1e9;
        vector<int> dp(n, inf);
        auto calc = [&](auto self, int u) -> int {
                if (dp[u] != inf) {
                        return dp[u];
                }
                for (auto v : g[u]) {
                        if (dist[v] > dist[u]) {
                                chmin(dp[u], self(self, v));
                        } else {
                                chmin(dp[u], dist[v]);
                        }
                }
                chmin(dp[u], dist[u]);
                return dp[u];
        };
        rep(i, n) {
                calc(calc, i);
        }
        cout << dp << '\n';
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
