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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> tor(n), tod(m);
        rep(i, k) {
                int y, x;
                cin >> y >> x;
                y --, x --;
                tor[y].push_back(x);
                tod[x].push_back(y);
        }
        rep(i, n) {
                sort(all(tor[i]));
        }
        rep(i, m) {
                sort(all(tod[i]));
        }
        int y = 0, x = 0;
        int r = m;
        int l = -1;
        int u = -1;
        int d = n;
        ll tot = 1;
        bool first = true;
        while (true) {
                // right
                {
                        int nxt = r - 1;
                        if (tor[y].size()) {
                                int p = upper_bound(all(tor[y]), x) - tor[y].begin();
                                if (p < tor[y].size()) {
                                        chmin(nxt, tor[y][p] - 1);
                                }
                        }
                        if (x == nxt) {
                                if (not first) {
                                        break;
                                }
                        }
                        tot += abs(nxt - x);
                        x = nxt;
                        u = y;
                }
                first = false;
                // down
                {
                        int nxt = d - 1;
                        if (tod[x].size()) {
                                int p = upper_bound(all(tod[x]), y) - tod[x].begin();
                                if (p < tod[x].size()) {
                                        chmin(nxt, tod[x][p] - 1);
                                }
                        }
                        if (y == nxt) {
                                break;
                        }
                        tot += abs(nxt - y);
                        y = nxt;
                        r = x;
                }
                // left
                {
                        int nxt = l + 1;
                        if (tor[y].size()) {
                                int p = lower_bound(all(tor[y]), x) - tor[y].begin();
                                p --;
                                if (p >= 0) {
                                        chmax(nxt, tor[y][p] + 1);
                                }
                        }
                        if (x == nxt) {
                                break;
                        }
                        tot += abs(nxt - x);
                        x = nxt;
                        d = y;
                }
                // up
                {
                        int nxt = u + 1;
                        if (tod[x].size()) {
                                int p = lower_bound(all(tod[x]), y) - tod[x].begin();
                                p --;
                                if (p >= 0) {
                                        chmax(nxt, tod[x][p] + 1);
                                }
                        }
                        if (y == nxt) {
                                break;
                        }
                        tot += abs(nxt - y);
                        y = nxt;
                        l = x;
                }
        }
        if (tot + k == (ll) n * m) {
                cout << "Yes\n";
        } else {
                cout << "No\n";
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
