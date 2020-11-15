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

vector<int> Dijkstra(int start, const vector<vector<int>> &g) {
        int n = (int) g.size();
        vector<int> dist(n, 1 << 30);
        priority_queue<pair<int, int>> que;
        dist[start] = 0;
        que.push({0, start});
        while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int u = p.second;
                for (auto v : g[u]) {
                        if (dist[v] > dist[u] + 1) {
                                dist[v] = dist[u] + 1;
                                que.push({-dist[v], v});
                        }
                }
        }
        return dist;
}

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n), rg(n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                rg[b].push_back(a);
        }
        int k;
        cin >> k;
        vector<int> p(k);
        rep(i, k) {
                cin >> p[i];
                p[i] --;
        }
        int s = p.front();
        int t = p.back();
        auto dist = Dijkstra(t, rg);
        int mi = 0, ma = 0;
        rep(i, (int) p.size() - 1) {
                int u = p[i];
                int v = p[i + 1];
                if (dist[u] <= dist[v]) {
                        mi ++;
                        ma ++;
                } else {
                        bool f = false;
                        for (int w : g[u]) {
                                if (w != v && dist[w] == dist[v]) {
                                        f = true;
                                        break;
                                }
                        }
                        if (f) {
                                ma ++;
                        }
                }
        }
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
