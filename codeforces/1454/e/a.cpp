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
        rep(i, n) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        vector<int> tmp, cyc;
        vector<bool> used(n);
        function<bool (int, int)> dfs = [&](int u, int prev) {
                if (used[u]) {
                        cyc = tmp;
                        return true;
                }
                used[u] = true;
                for (int v : g[u]) if (v != prev) {
                        tmp.push_back(v);
                        if (dfs(v, u)) {
                                return true;
                        }
                        tmp.pop_back();
                }
                return false;
        };
        tmp.push_back(0);
        dfs(0, -1);
        tmp.pop_back();
        reverse(all(cyc));
        int v = cyc.front();
        vector<int> cycle = {v};
        rep(i, cyc.size()) if (i) {
                if (cyc[i] == v) {
                        break;
                }
                cycle.push_back(cyc[i]);
        }
        set<int> cyclest;
        rep(i, cycle.size()) {
                cyclest.insert(cycle[i]);
        }
        int sz = cycle.size();
        int r = n - sz;
        ll ans = (ll) n * (n - 1);
        int cnt = 0;
        function<void (int, int)> dfs2 = [&](int u, int prev) {
                cnt ++;
                for (int v : g[u]) if (v != prev && cyclest.count(v) == 0) {
                        dfs2(v, u);
                }
        };
        rep(i, cycle.size()) {
                cnt = 0;
                dfs2(cycle[i], -1);
                ans -= (ll) cnt * (cnt - 1) / 2;
        }
        cout << ans << '\n';
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
