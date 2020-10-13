#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

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
        int root = -1;
        rep(i, n) {
                if (g[i].size() > 1) {
                        root = i;
                        break;
                }
        }
        assert(root != -1);
        bool odd = false, even = false;
        int ma = 0;
        function<void (int, int, int)> dfs = [&](int u, int prev, int dep) {
                int c = 0;
                bool f = false;
                for (int v : g[u]) if (v != prev) {
                        if (g[v].size() == 1) {
                                if (!f) {
                                        ma ++;
                                }
                                f = true;
                        } else {
                                ma ++;
                        }
                        dfs(v, u, dep + 1);
                }
                if (g[u].size() == 1) {
                        if (dep & 1) {
                                odd = true;
                        } else {
                                even = true;
                        }
                }
        };
        dfs(root, -1, 0);
        int mi = (even && odd ? 3 : 1);
        cout << mi << " " << ma << '\n';
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
