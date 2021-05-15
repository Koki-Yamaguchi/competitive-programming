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

struct StronglyConnectedComponent {
        int n;
        vector<bool> used;
        vector<int> order, cmp;
        vector<vector<int>> g, rg;
        StronglyConnectedComponent(int x) {
                n = x;
                g.resize(x);
                rg.resize(x);
                used.resize(x);
                cmp.resize(x);
        }
        void add_edge(int from, int to) {
                g[from].push_back(to);
                rg[to].push_back(from);
        }
        void dfs(int u) {
                used[u] = true;
                for (auto v : g[u]) if (!used[v]) {
                        dfs(v);
                }
                order.push_back(u);
        }
        void rdfs(int u, int k) {
                used[u] = true;
                cmp[u] = k;
                for (auto v : rg[u]) if (!used[v]) {
                        rdfs(v, k);
                }
        }
        int init() {
                used.assign(n, false);
                for (int u = 0; u < n; u ++) {
                        if (!used[u]) {
                                dfs(u);
                        }
                }
                used.assign(n, false);
                int k = 0;
                for (int i = order.size() - 1; i >= 0; i --) {
                        if (!used[order[i]]) {
                                rdfs(order[i], k ++);
                        }
                }
                return k;
        }
};

void solve() {
        int n, m;
        cin >> n >> m;
        StronglyConnectedComponent scc(n);
        vector<vector<pair<int, int>>> g(n);
        rep(i, m) {
                int a, b, c;
                cin >> a >> b >> c;
                a --, b --;
                g[a].push_back({b, c});
                scc.add_edge(a, b);
        }
        scc.init();
        int k = 0;
        rep(i, n) {
                k = max(k, scc.cmp[i] + 1);
        }
        vector<int> cnt(k);
        rep(i, n) {
                cnt[scc.cmp[i]] ++;
        }
        vector<int> rpr(k, -1);
        rep(i, n) {
                if (rpr[scc.cmp[i]] == -1) {
                        rpr[scc.cmp[i]] = i;
                }
        }
        vector<ll> dist(n);
        auto dfs = [&](auto self, int u) -> void {
                // TODO
        };
        rep(i, k) {
                int st = rpr[i];
                dfs(dfs, st);
        }
        int q;
        cin >> q;
        while (q --) {
                int v, s, t;
                cin >> v >> s >> t;
                if (s == 0) {
                        cout << "YES\n";
                        continue;
                }
                v --;
                if (cnt[scc.cmp[v]] == 1) {
                        cout << "NO\n";
                        continue;
                }
                // TODO
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
