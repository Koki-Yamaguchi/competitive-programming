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
        vector<int> mind(n, 1e9);
        auto dfs0 = [&](auto self, int u, int prev, int dep) -> void {
                for (int v : g[u]) if (v != prev) {
                        self(self, v, u, dep + 1);
                        mind[u] = min(mind[u], mind[v]);
                }
                if (u != 0 && g[u].size() == 1) {
                        mind[u] = dep;
                }
        };
        dfs0(dfs0, 0, -1, 0);
        int k = 0;
        auto dfs1 = [&](auto self, int u, int prev) -> int {
                if (u != 0 && g[u].size() == 1) {
                        return 1;
                }
                vector<int> tos;
                for (int v : g[u]) if (v != prev) {
                        tos.push_back(v);
                }
                sort(all(tos), [&](auto a, auto b) {
                        return mind[a] > mind[b];
                });
                if (u == 0) {
                        rep(i, tos.size()) if (i) {
                                int v = tos[i];
                                int l = self(self, v, u);
                                k = max(k, l + 1);
                        }
                        int l = self(self, tos[0], u);
                        k = max(k, l);
                        return -1;
                } else {
                        rep(i, tos.size()) {
                                int v = tos[i];
                                int l = self(self, v, u);
                                k = max(k, l + 1);
                                if (i + 1 == tos.size()) {
                                        return l + 1;
                                }
                        }
                }
                assert(false);
        };
        dfs1(dfs1, 0, -1);
        cout << k << '\n';
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
