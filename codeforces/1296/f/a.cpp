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
        vector<int> f(n - 1, -1);
        vector<vector<pair<int, int>>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back({b, i});
                g[b].push_back({a, i});
        }
        int m;
        cin >> m;
        function<void (int, int, int, int, vector<pair<int, int>>&, vector<pair<int, int>>&)> dfs = [&](int u, int prev, int tgt, int col, vector<pair<int, int>> &path, vector<pair<int, int>> &final_path) {
                if (u == tgt) {
                        final_path = path;
                        return;
                }
                for (pair<int, int> e : g[u]) if (e.first != prev) {
                        int v = e.first;
                        path.push_back({v, e.second});
                        dfs(v, u, tgt, col, path, final_path);
                        path.pop_back();
                }
        };
        vector<vector<pair<int, int>>> final_paths;
        vector<pair<pair<int, int>, int>> qs(m);
        rep(i, m) {
                int a, b, c;
                cin >> a >> b >> c;
                a --, b --;
                vector<pair<int, int>> path = {{ a, -1 }}, final_path;
                dfs(a, -1, b, c, path, final_path);
                for (int i = 1; i < final_path.size(); i ++) {
                        int idx = final_path[i].second;
                        f[idx] = max(f[idx], c);
                }
                qs[i].first.first = a;
                qs[i].first.second = b;
                qs[i].second = c;
                final_paths.push_back(final_path);
        }
        rep(i, n) {
                if (f[i] == -1) {
                        f[i] = 1;
                }
        }
        bool ok = true;
        rep(i, m) {
                int fff = qs[i].second;
                int act = 1e9;
                for (int j = 1; j < final_paths[i].size(); j ++) {
                        int idx = final_paths[i][j].second;
                        act = min(act, f[idx]);
                }
                if (fff != act) {
                        ok = false;
                        break;
                }
        }
        if (!ok) {
                cout << -1 << '\n';
        } else {
                cout << f << '\n';
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
