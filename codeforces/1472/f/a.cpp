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
        vector<pair<int, int>> ps;
        ps.emplace_back(0, 0);
        ps.emplace_back(0, 1);
        rep(i, m) {
                int y, x;
                cin >> y >> x;
                y --;
                ps.emplace_back(x, y);
        }
        ps.emplace_back(n + 1, 0);
        ps.emplace_back(n + 1, 1);
        sort(all(ps)); // x, y
        vector<pair<int, int>> b; // 1 blocked
        int prevx = 0;
        m = ps.size();
        rep(i, m) {
                if (i && ps[i].first == ps[i - 1].first) {
                        continue;
                }
                if (i) {
                        int d = ps[i].first - prevx - 1;
                        if (d & 1) {
                                b.emplace_back(0, 0);
                        }
                }
                if (i + 1 < m && ps[i].first == ps[i + 1].first) {
                        b.emplace_back(1, 1);
                } else if (ps[i].second == 0) {
                        b.emplace_back(1, 0);
                } else {
                        b.emplace_back(0, 1);
                }
                prevx = ps[i].first;
        }
        int k = b.size();
        vector<bool> can(4);
        can[3] = true;
        rep(i, k) if (i) {
                vector<bool> nxt(4);
                if (b[i].first == 0 && b[i].second == 0) {
                        nxt[0] = can[0] || can[3];
                        nxt[1] = can[2];
                        nxt[2] = can[1];
                        nxt[3] = can[0] || can[3];
                } else if (b[i].first == 0 && b[i].second == 1) {
                        nxt[1] = can[3];
                        nxt[3] = can[1];
                } else if (b[i].first == 1 && b[i].second == 0) {
                        nxt[2] = can[3];
                        nxt[3] = can[2];
                } else {
                        nxt[3] = can[0] || can[3];
                }
                swap(can, nxt);
        }
        cout << (can[3] ? "YES\n" : "NO\n");
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
