#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
vector<int> Centroid(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}
 
void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        auto cents = Centroid(g);
        if (cents.size() == 1) {
                cout << 0 + 1 << " " << g[0][0] + 1 << '\n';
                cout << 0 + 1 << " " << g[0][0] + 1 << '\n';
        } else {
                int c = cents[0];
                int cc = cents[1];
                int lfp = -1;
                int lf = -1;
                function<void (int, int)> dfs = [&](int u, int prev) {
                        for (int v : g[u]) if (v != prev) {
                                dfs(v, u);
                        }
                        if (g[u].size() == 1) {
                                lfp = prev;
                                lf = u;
                        }
                };
                dfs(c, cc);
                assert(lfp != cc);
                cout << lfp + 1 << " " << lf + 1 << '\n';
                cout << lf + 1 << " " << cc + 1 << '\n';
        }
}
 
int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
