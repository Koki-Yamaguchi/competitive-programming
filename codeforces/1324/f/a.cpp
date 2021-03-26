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

// maximize (#white(1) - #black(0))
vector<int> slv(int n, vector<int> &a, vector<vector<int>> &g) {
        vector<int> ma(n);
        function<void (int, int)> dfs0 = [&](int u, int prev) {
                ma[u] = a[u] ? 1 : -1;
                for (int v : g[u]) if (v != prev) {
                        dfs0(v, u);
                        if (ma[v] > 0) {
                                ma[u] += ma[v];
                        }
                }
        };
        dfs0(0, -1);
        vector<int> ans(n);
        function<void (int, int, int)> dfs1 = [&](int u, int prev, int par) {
                for (int v : g[u]) if (v != prev) {
                        dfs1(v, u, par + ma[u] - (ma[v] > 0 ? ma[v] : 0));
                }
                ans[u] = ma[u] + (par > 0 ? par : 0);
        };
        dfs1(0, -1, 0);
        return ans;
}

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        auto ans = slv(n, a, g);
        cout << ans << '\n';
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
