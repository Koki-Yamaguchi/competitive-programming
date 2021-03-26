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
        if (n & 1) {
                vector<vector<pair<int, int>>> g(n);
                rep(i, n) {
                        rep(j, (n - 1) / 2) {
                                int to = (i + 1 + j) % n;
                                g[i].emplace_back(to, 1);
                                g[to].emplace_back(i, -1);
                        }
                }
                rep(i, n) {
                        sort(all(g[i]));
                        for (int j = i + 1; j < n; j ++) {
                                cout << g[i][j - 1].second << " ";
                        }
                }
                cout << '\n';
        } else {
                vector<vector<pair<int, int>>> g(n);
                rep(i, n) {
                        rep(j, n / 2) {
                                int to = (i + 1 + j) % n;
                                if (j < n / 2 - 1) {
                                        g[i].emplace_back(to, 1);
                                        g[to].emplace_back(i, -1);
                                } else if (i < n / 2 && j == n / 2 - 1) {
                                        g[i].emplace_back(to, 0);
                                        g[to].emplace_back(i, 0);
                                }
                        }
                }
                rep(i, n) {
                        sort(all(g[i]));
                        for (int j = i + 1; j < n; j ++) {
                                cout << g[i][j - 1].second << " ";
                        }
                }
                cout << '\n';
        }
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
