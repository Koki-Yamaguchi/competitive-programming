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
        vector<int> c(n);
        int root = -1;
        rep(i, n) {
                int p;
                cin >> p >> c[i];
                p --;
                if (p != -1) {
                        g[p].push_back(i);
                } else {
                        root = i;
                }
        }
        bool ng = false;
        vector<vector<int>> arr(n);
        auto dfs = [&](auto self, int u) -> void {
                for (int v : g[u]) {
                        self(self, v);
                        for (auto it : arr[v]) {
                                arr[u].push_back(it);
                        }
                }
                if (arr[u].size() < c[u]) {
                        ng = true;
                        return;
                }
                arr[u].insert(arr[u].begin() + c[u], u);
        };
        dfs(dfs, root);
        if (ng) {
                cout << "NO\n";
                return;
        }
        vector<int> ans(n);
        rep(i, n) {
                ans[arr[root][i]] = i + 1;
        }
        cout << "YES\n";
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
