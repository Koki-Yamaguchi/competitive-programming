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

vector<int> EulerianTrail(const int s, vector<vector<int>> &g, const bool directed) {
        function<void (int, vector<int> &)> dfs = [&](int u, vector<int> &trail) {
                while (!g[u].empty()) {
                        int v = g[u].back();
                        g[u].pop_back();
                        if (!directed) {
                                for (int i = 0; i < g[v].size(); i ++) {
                                        if (g[v][i] == u) {
                                                g[v].erase(g[v].begin() + i);
                                                break;
                                        }
                                }
                        }
                        dfs(v, trail);
                }
                trail.push_back(u);
        };
        vector<int> trail;
        dfs(s, trail);
        reverse(trail.begin(), trail.end());
        return trail;
}

void solve() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(k);
        rep(i, k) {
                rep(j, i + 1) {
                        if (i != j) {
                                g[i].push_back(j);
                        }
                        g[j].push_back(i);
                }
        }
        auto trail = EulerianTrail(0, g, true);
        vector<int> sub;
        rep(i, trail.size()) if (i) {
                sub.push_back(trail[i]);
        }
        string ans = "";
        ans += (char) ('a' + trail[0]);
        rep(i, n - 1) {
                ans += (char) ('a' + sub[i % sub.size()]);
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
