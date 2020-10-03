#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        map<int, int> cnt;
        rep(i, n) {
                cnt[a[i]] ++;
                cnt[b[i]] ++;
        }
        for (auto it : cnt) {
                if (it.second != 2) {
                        cout << -1 << '\n';
                        return;
                }
        }
        map<int, int> pos;
        vector<vector<pair<int, int>>> g(n);
        rep(i, n) {
                if (pos.count(a[i]) == 0) {
                        pos[a[i]] = i * 2;
                } else {
                        int p = pos[a[i]];
                        int idx = p / 2;
                        if (p % 2 == 0) {
                                g[idx].emplace_back(i, 1);
                                g[i].emplace_back(idx, 1);
                        } else {
                                g[idx].emplace_back(i, 0);
                                g[i].emplace_back(idx, 0);
                        }
                }
                if (pos.count(b[i]) == 0) {
                        pos[b[i]] = i * 2 + 1;
                } else {
                        int p = pos[b[i]];
                        int idx = p / 2;
                        if (p % 2 == 0) {
                                g[idx].emplace_back(i, 0);
                                g[i].emplace_back(idx, 0);
                        } else {
                                g[idx].emplace_back(i, 1);
                                g[i].emplace_back(idx, 1);
                        }
                }
        }
        /*
        rep(u, n) {
                for (auto v : g[u]) {
                        cerr << u << " -> " << v.first << " " << v.second << endl;
                }
        }
        */
        vector<int> color(n, -1);
        int c0 = 0, c1 = 0;
        vector<int> c0v, c1v;
        function<void (int, int)> dfs = [&](int u, int c) {
                color[u] = c;
                if (c) {
                        c0 ++;
                        c0v.push_back(u);
                } else {
                        c1 ++;
                        c1v.push_back(u);
                }
                for (pair<int, int> e : g[u]) {
                        int v = e.first;
                        int rev = e.second;
                        if (color[v] != -1) {
                                assert(color[v] == (c ^ rev));
                                continue;
                        }
                        dfs(v, c ^ rev);
                }
        };
        int ans = 0;
        vector<int> res;
        rep(i, n) {
                if (color[i] == -1) {
                        dfs(i, 0);
                }
                ans += min(c0, c1);
                if (c0 < c1) {
                        for (auto it : c0v) res.push_back(it);
                } else {
                        for (auto it : c1v) res.push_back(it);
                }
                c0 = 0, c1 = 0;
                c0v.clear(), c1v.clear();
        }
        cout << ans << '\n';
        rep(i, res.size()) {
                cout << res[i] + 1 << " ";
        }
        cout << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
