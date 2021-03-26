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

const int MOD = 998244353;

long long ModPow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % MOD;
                x = x * x % MOD;
                n >>= 1;
        }
        return res;
}

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(2 * n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b + n].push_back(a + n);
        }
        rep(i, n) {
                g[i].push_back(i + n);
                g[i + n].push_back(i);
        }
        vector<vector<ll>> dist(n, vector<ll> (30, 1e18));
        priority_queue<pair<int, int>> que;
        dist[0][0] = 0;
        que.push({0, 0});
        while (!que.empty()) {
                auto p = que.top(); que.pop();
                int u = p.second;
                for (auto v : g[u]) {
                        if (v % n == u % n) {
                                rep(i, 29) {
                                        if (dist[v][i + 1] > dist[u][i] + ModPow(2, i)) {
                                                dist[v][i + 1] = dist[u][i] + ModPow(2, i);
                                                que.push({-dist[v][i + 1], v});
                                        }
                                }
                        } else {
                                rep(i, 30) {
                                        if (dist[v][i] > dist[u][i] + 1) {
                                                dist[v][i] = dist[u][i] + 1;
                                                que.push({-dist[v][i], v});
                                        }
                                }
                        }
                }
        }
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
