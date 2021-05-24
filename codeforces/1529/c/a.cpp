#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> ostream& operator << (ostream& os, const set<T> &p) { os << "{"; for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << *it; } os << "}"; return os; }
template<typename T, typename U> ostream& operator << (ostream& os, const map<T, U> &p) { for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << "{" << (*it).first << ": " << (*it).second << "}"; } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        vector<pair<int, int>> p(n);
        rep(i, n) {
                int l, r;
                cin >> l >> r;
                p[i] = make_pair(l, r);
        }
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        vector<ll> dpl(n), dpr(n);
        auto dfs = [&](auto self, int u, int prev) -> void {
                ll l = p[u].first;
                ll r = p[u].second;
                ll lv = 0, rv = 0;
                for (auto v : g[u]) if (v != prev) {
                        self(self, v, u);
                        lv += max(abs(p[v].first - l) + dpl[v], abs(p[v].second - l) + dpr[v]);
                        rv += max(abs(p[v].first - r) + dpl[v], abs(p[v].second - r) + dpr[v]);
                }
                dpl[u] = lv;
                dpr[u] = rv;
        };
        dfs(dfs, 0, -1);
        cout << max(dpl[0], dpr[0]) << '\n';
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
