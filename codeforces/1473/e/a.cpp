#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < m; i ++) {
                int a, b, c;
                cin >> a >> b >> c;
                a --, b --;
                g[a].emplace_back(b, c);
                g[b].emplace_back(a, c);
        }
        const ll inf = 1e18;
        vector<vector<ll>> dist(n, vector<ll> (4, inf));
        using hoge = pair<ll, pair<int, int>>;
        priority_queue<hoge, vector<hoge>, greater<hoge>> que;
        dist[0][0] = 0;
        que.push({ 0, {0, 0} });
        while (!que.empty()) {
                auto p = que.top(); que.pop();
                int u = p.second.first;
                int cur = p.second.second;
                ll cost = p.first;
                if (dist[u][cur] < cost) continue;
                for (auto e : g[u]) {
                        int v = e.first;
                        ll c = e.second;
                        rep(nxt, 4) {
                                if ((cur | nxt) != nxt) continue;
                                ll ex = c;
                                if ((cur & 1) ^ (nxt & 1)) ex -= c;
                                if (((cur >> 1) & 1) ^ ((nxt >> 1) & 1)) ex += c;
                                if (chmin(dist[v][nxt], dist[u][cur] + ex)) {
                                        que.push({dist[v][nxt], {v, nxt}});
                                }
                        }
                }
        }
        rep(i, n) if (i) {
                cout << dist[i][3] << " \n"[i == n - 1];
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
