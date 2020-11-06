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

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        map<pair<int, int>, int> id;
        vector<int> ans(n - 1, -1);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
                id[minmax(a, b)] = i;
        }
        int r = -1;
        rep(i, n) {
                if (g[i].size() >= 3) {
                        r = i;
                        break;
                }
        }
        int k = 0;
        if (r != -1) {
                for (int u : g[r]) {
                        if (ans[id[minmax(r, u)]] == -1) {
                                ans[id[minmax(r, u)]] = k ++;
                        }
                }
                rep(i, n) {
                        for (int u : g[i]) {
                                if (i != r && u != r) {
                                        if (ans[id[minmax(i, u)]] == -1) {
                                                ans[id[minmax(i, u)]] = k ++;
                                        }
                                }
                        }
                }
        } else {
                rep(i, n) {
                        for (int u : g[i]) {
                                if (ans[id[minmax(i, u)]] == -1) {
                                        ans[id[minmax(i, u)]] = k ++;
                                }
                        }
                }
        }
        rep(i, n - 1) {
                cout << ans[i] << '\n';
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
