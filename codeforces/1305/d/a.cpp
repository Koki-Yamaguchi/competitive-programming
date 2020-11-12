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

vector<int> Centroid(const vector<vector<int>> &g, int ltot) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = (g[u].size() == 1);
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > ltot / 2) is_centroid = false;
                }
                if (ltot - sz[u] > ltot / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}

void solve() {
        int n; cin >> n;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        auto ask = [](int u, int v) {
                cout << "? " << u + 1 << " " << v + 1 << endl;
                int res;
                cin >> res;
                return res - 1;
        };
        auto answer = [](int ans) {
                cout << "! " << ans + 1 << endl;
                return;
        };
        if (n == 2) {
                answer(ask(0, 1));
                return;
        }
        int ltot = 0;
        rep(i, n) {
                ltot += (g[i].size() == 1);
        }
        auto cs = Centroid(g, ltot);
        int c = -1;
        for (auto it : cs) {
                if (g[it].size() != 1) {
                        c = it;
                }
        }
        vector<vector<int>> vs;
        vector<int> v;
        function<void (int, int)> dfs0 = [&](int u, int prev) {
                if (g[u].size() == 1) {
                        v.push_back(u);
                }
                for (int v : g[u]) if (v != prev) {
                        dfs0(v, u);
                }
        };
        for (int u : g[c]) {
                v.clear();
                dfs0(u, c);
                vs.push_back(v);
        }
        sort(all(vs), [&](const vector<int> &a, const vector<int> &b) {
                return a.size() < b.size();
        });
        vector<int> alll;
        for (auto it : vs) {
                for (auto itit : it) {
                        alll.push_back(itit);
                }
        }

        assert(vs[vs.size() - 1].size() <= alll.size() / 2);

        vector<pair<int, int>> ps;
        int k = alll.size() / 2;
        for (int i = 0; i < alll.size() / 2; i ++) {
                ps.emplace_back(alll[i], alll[i + k]);
        }
        if ((int) alll.size() & 1) {
                ps.emplace_back(alll[(int) alll.size() - 1], alll[0]);
        }
        function<void (int, int, int, vector<int>&, vector<int>&)> dfs1 = [&](int u, int prev, int tgt, vector<int> &path, vector<int> &res) {
                if (u == tgt) {
                        res = path;
                        return;
                }
                for (int v : g[u]) if (v != prev) {
                        path.push_back(v);
                        dfs1(v, u, tgt, path, res);
                        path.pop_back();
                        if (res.size() != 0) {
                                return;
                        }
                }
        };
        vector<int> parent(n, -1);
        assert(ps.size() <= n / 2);
        rep(i, ps.size()) {
                auto [u, v] = ps[i];
                int par = ask(u, v);
                vector<int> res0, res1;
                vector<int> path0 = { u };
                dfs1(u, -1, par, path0, res0);
                vector<int> path1 = { v };
                dfs1(v, -1, par, path1, res1);
                rep(j, (int) res0.size() - 1) {
                        if (parent[res0[j]] != -1) {
                                assert(parent[res0[j]] == res0[j + 1]);
                        } else {
                                parent[res0[j]] = res0[j + 1];
                        }
                }
                rep(j, (int) res1.size() - 1) {
                        if (parent[res1[j]] != -1) {
                                assert(parent[res1[j]] == res1[j + 1]);
                        } else {
                                parent[res1[j]] = res1[j + 1];
                        }
                }
        }
        int cnt = count(all(parent), -1);
        assert(cnt == 1);
        rep(i, n) {
                if (parent[i] == -1) {
                        answer(i);
                        return;
                }
        }
        assert(false);
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
