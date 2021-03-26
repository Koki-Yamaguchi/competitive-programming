#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

// bipart -> true
bool dfs_same_color(int u, int prev, int type, const vector<int> &types, int color, const vector<vector<int>> &g, vector<int> &colors) {
        colors[u] = color;
        for (int v : g[u]) if (v != prev && types[v] == type) {
                int nxt_color = (color % 2 == 0 ? color + 1 : color - 1);
                if (colors[v] == -1) {
                        if (not dfs_same_color(v, u, type, types, nxt_color, g, colors)) {
                                return false;
                        }
                } else if (colors[v] != nxt_color) {
                        return false;
                }
        }
        return true;
}

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> types(n);
        vector<vector<int>> vs(k), g(n);
        rep(i, n) {
                cin >> types[i];
                types[i] --;
                vs[types[i]].push_back(i);
        }
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        ll ans = (ll) k * (k - 1) / 2;
        int rest = k;
        vector<int> colors(n, -1);
        vector<bool> banned(k);
        rep(type, k) {
                int color = 0;
                for (int v : vs[type]) {
                        if (colors[v] != -1) {
                                continue;
                        }
                        bool bip = dfs_same_color(v, -1, type, types, color, g, colors);
                        if (not bip) {
                                ans -= rest - 1;
                                rest --;
                                banned[type] = true;
                                break;
                        }
                        color += 2;
                }
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
