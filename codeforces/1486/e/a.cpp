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
        rep(i, m) {
                int a, b, c;
                cin >> a >> b >> c;
                a --, b --;
                g[a].emplace_back(b, c);
                g[b].emplace_back(a, c);
        }
        const int wma = 50;
        const ll inf = 1e18;
        vector<vector<ll>> wdp(n, vector<ll> (wma + 1, inf));
        vector<ll> ans(n, inf);
        ans[0] = 0;
        using state_t = tuple<ll, int, int, int>;
        priority_queue<state_t, vector<state_t>, greater<state_t>> que;
        que.emplace(0, 0, 0, -1);
        while (not que.empty()) {
                auto [d, color, u, w] = que.top(); que.pop();
                if (color == 0) {
                        if (ans[u] < d) {
                                continue;
                        }
                        assert(w == -1);
                        for (auto e : g[u]) {
                                int v = e.first;
                                int www = e.second;
                                if (wdp[v][www] > ans[u]) {
                                        wdp[v][www] = ans[u];
                                        que.emplace(wdp[v][www], 1, v, www);
                                }
                        }
                } else {
                        if (wdp[u][w] < d) {
                                continue;
                        }
                        for (auto e : g[u]) {
                                int v = e.first;
                                int www = e.second;
                                ll cost = (ll) (w + www) * (w + www);
                                if (ans[v] > wdp[u][w] + cost) {
                                        ans[v] = wdp[u][w] + cost;
                                        que.emplace(ans[v], 0, v, -1);
                                }
                        }
                }
        }
        rep(i, n) {
                cout << (ans[i] == inf ? -1 : ans[i]) << " \n"[i == n - 1];
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
