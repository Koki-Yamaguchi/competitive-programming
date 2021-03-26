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

vector<int> calc(const vector<set<int>> &g, const vector<int> &from, const vector<int> &to) {
        int n = to.size();
        vector<int> idxs(n);
        iota(all(idxs), 0);
        sort(all(idxs), [&](auto a, auto b) {
                return to[a] < to[b];
        });
        vector<int> res(from.size(), -1);
        vector<int> nxt(n);
        for (int i = n - 1; i >= 0; i --) {
                if (to[idxs[i]] != -1) {
                        nxt[i] = i;
                } else {
                        if (i == n - 1) {
                                nxt[i] = n;
                        } else {
                                nxt[i] = nxt[i + 1];
                        }
                }
        }
        rep(i, from.size()) {
                if (from[i] == -1) {
                        continue;
                }
                int j = nxt[0];
                while (j != n) {
                        int idx = idxs[j];
                        assert(to[idx] != -1);
                        if (g[i].count(idx) == 0) {
                                res[i] = from[i] + to[idx];
                                break;
                        }
                        j ++;
                        if (j == n) break;
                        j = nxt[j];
                }
        }
        return res;
}

void solve() {
        vector<int> n(4);
        rep(i, 4) {
                cin >> n[i];
        }
        vector<vector<int>> a(4);
        rep(i, 4) {
                a[i].resize(n[i]);
                rep(j, n[i]) {
                        cin >> a[i][j];
                }
        }
        vector<vector<set<int>>> g(3);
        g[0].resize(n[1]);
        g[1].resize(n[1]);
        g[2].resize(n[2]);
        rep(i, 3) {
                int m;
                cin >> m;
                rep(j, m) {
                        int a, b;
                        cin >> a >> b;
                        a --, b --;
                        if (i == 0) {
                                g[i][b].insert(a);
                        } else {
                                g[i][a].insert(b);
                        }
                }
        }
        auto res0 = calc(g[0], a[1], a[0]);
        auto res1 = calc(g[2], a[2], a[3]);
        auto res = calc(g[1], res0, res1);
        const int inf = 1e9;
        int ans = inf;
        rep(i, res.size()) {
                if (res[i] != -1) {
                        chmin(ans, res[i]);
                }
        }
        if (ans == inf) {
                ans = -1;
        }
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
