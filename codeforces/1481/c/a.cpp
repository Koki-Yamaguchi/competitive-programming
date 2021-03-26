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
        vector<int> a(n), b(n), c(m);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        map<int, int> needcnt;
        rep(i, n) {
                if (a[i] != b[i]) {
                        needcnt[b[i]] ++;
                }
        }
        map<int, int> bcnt;
        rep(i, n) {
                bcnt[b[i]] ++;
        }
        map<int, int> has;
        rep(i, m) {
                cin >> c[i];
                has[c[i]] ++;
        }
        bool ok = true;
        for (auto it : needcnt) {
                int color = it.first;
                int cnt = it.second;
                int hs = has[color];
                if (hs < cnt) {
                        ok = false;
                        break;
                }
        }
        if (!ok) {
                cout << "NO\n";
                return;
        }
        if (bcnt[c[m - 1]] == 0) {
                cout << "NO\n";
                return;
        }
        cout << "YES\n";
        int trashpos = -1;
        rep(i, n) {
                if (c[m - 1] == b[i] && a[i] != b[i]) {
                        trashpos = i;
                        break;
                }
        }
        if (trashpos == -1) {
                rep(i, n) {
                        if (c[m - 1] == b[i]) {
                                trashpos = i;
                                break;
                        }
                }
        }
        assert(trashpos != -1);
        map<int, vector<int>> pos;
        rep(i, n) {
                if (a[i] != b[i]) {
                        pos[b[i]].push_back(i);
                }
        }
        vector<int> ans(m);
        rep(i, m) {
                if (pos[c[i]].size()) {
                        int idx = pos[c[i]].back();
                        pos[c[i]].pop_back();
                        ans[i] = idx + 1;
                } else {
                        ans[i] = trashpos + 1;
                }
        }
        cout << ans << '\n';
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
