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
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        const int inf = 1e9;
        vector<vector<int>> dp(3, vector<int> (n, inf));
        vector<vector<vector<int>>> use(3, vector<vector<int>> (n));
        // when dp[i][u] is optimal,
        // use all edges between u and v,
        // where v is a vertice in set use[u]
        auto dfs0 = [&](auto self, int u, int prev) -> void {
                vector<int> ch;
                vector<vector<int>> chdp(3);
                int sum = 0;
                for (auto v : g[u]) if (v != prev) {
                        self(self, v, u);
                        ch.push_back(v);
                        rep(i, 3) {
                                chdp[i].push_back(dp[i][v]);
                        }
                        sum += dp[0][v];
                }
                int chsz = ch.size();
                if (chsz == 0) {
                        dp[0][u] = 0;
                        dp[1][u] = 0;
                        return;
                }
                vector<pair<int, int>> diff;
                rep(i, chsz) {
                        diff.push_back({- chdp[0][i] + chdp[1][i], ch[i]});
                }
                sort(all(diff));
                // dp0: use 0 edge
                {
                        if (chmin(dp[0][u], sum + chsz - 0)) {
                                use[0][u] = vector<int>{};
                        }
                }
                // dp1:
                {
                        // use 1 edge
                        if (chmin(dp[1][u], sum + diff[0].first + chsz - 1)) {
                                use[1][u] = vector<int>{diff[0].second};
                        }
                        // use 0 edge but 1 node as an end of a path
                        if (chmin(dp[1][u], sum + chsz - 0)) {
                                use[1][u] = vector<int>{};
                        }
                }
                {
                // dp2: use 2 edge
                        if (diff.size() >= 2) {
                                if (chmin(dp[2][u], sum + diff[0].first + diff[1].first + chsz - 2)) {
                                        use[2][u] = vector<int>{diff[0].second, diff[1].second};
                                }
                        }
                }
                // dp0
                if (chmin(dp[0][u], min(dp[1][u], dp[2][u]))) {
                        if (dp[1][u] < dp[2][u]) {
                                use[0][u] = use[1][u];
                        } else {
                                use[0][u] = use[2][u];
                        }
                }
        };
        dfs0(dfs0, 0, -1);
        vector<vector<int>> pathg(n);
        vector<set<int>> useset(n);
        rep(i, n) {
                for (auto j : use[0][i]) {
                        pathg[i].push_back(j);
                        pathg[j].push_back(i);
                        useset[i].insert(j);
                        useset[j].insert(i);
                }
        }
        vector<bool> used(n);
        vector<int> pth;
        auto dfs1 = [&](auto self, int u, int prev) -> void {
                used[u] = true;
                pth.push_back(u);
                assert(pathg.size() <= 2); // fail!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                for (auto v : pathg[u]) if (v != prev) {
                        self(self, v, u);
                }
        };
        vector<vector<int>> paths;
        rep(i, n) {
                if (not used[i] && pathg[i].size() <= 1) {
                        dfs1(dfs1, i, -1);
                        paths.push_back(pth);
                        pth.clear();
                }
        }
        vector<pair<int, int>> remove;
        rep(i, n) {
                for (auto j : g[i]) {
                        if (useset[i].count(j) == 0) {
                                if (i < j) {
                                        remove.emplace_back(i, j);
                                }
                        }
                }
        }
        assert(remove.size() == (int) paths.size() - 1);
        vector<tuple<int, int, int, int>> ans;
        rep(i, (int) paths.size() - 1) {
                ans.push_back({remove[i].first, remove[i].second, paths[i].back(), paths[i + 1].front()});
        }
        rep(i, paths.size()) {
                cerr << "path" << endl;
                for (auto p : paths[i]) {
                        cerr << p + 1 << " ";
                }
                cerr << endl;
        }
        // fail here
        // assert(ans.size() == dp[0][0]);
        //                14    15
        cout << dp[0][0] << '\n';
        rep(i, ans.size()) {
                cout <<
                get<0>(ans[i]) + 1 << " " <<
                get<1>(ans[i]) + 1 << " " <<
                get<2>(ans[i]) + 1 << " " <<
                get<3>(ans[i]) + 1 << "\n";
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;
        t = 2;
        while (t --) {
                solve();
        }
        return 0;
}
