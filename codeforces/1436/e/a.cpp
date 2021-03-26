#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        vector<pair<int, int>> to(n, make_pair(-1, -1));
        vector<int> prev(n, -1);
        rep(i, n) {
                if (a[i]) {
                        if (prev[a[i] - 1] != -1) {
                                to[i].first = prev[a[i] - 1];
                        }
                }
                prev[a[i]] = i;
        }
        rep(i, n) prev[i] = -1;
        for (int i = n - 1; i >= 0; i --) {
                if (a[i]) {
                        if (prev[a[i] - 1] != -1) {
                                to[i].second = prev[a[i] - 1];
                        }
                }
                prev[a[i]] = i;
        }
        /*
        rep(i, n) {
                cerr << to[i].first << " " << to[i].second << '\n';
        }
        */
        vector<vector<int>> pos(n);
        rep(i, n) {
                pos[a[i]].push_back(i);
        }
        vector<pair<int, int>> valid(n, make_pair(-1, -1));
        bool allone = true;
        int ma = 0;
        rep(i, n) {
                if (a[i] == 0) {
                        valid[i] = make_pair(i, i);
                } else {
                        allone = false;
                }
                ma = max(ma, a[i]);
        }
        if (allone) {
                cout << 1 << '\n';
                return;
        }
        rep(i, n) if (i) {
                bool ok = false;
                bool in = false;
                for (auto p : pos[i]) {
                        in = true;
                        int l = to[p].first;
                        if (l != -1) {
                                if (valid[l].first != -1 || valid[l].second < p) {
                                        valid[p].first = l;
                                        ok = true;
                                }
                        }
                        int r = to[p].second;
                        if (r != -1) {
                                if (valid[r].second != -1 || p < valid[r].first) {
                                        valid[p].second = r;
                                        ok = true;
                                }
                        }
                }
                if (in && !ok) {
                        cout << i + 1 << '\n';
                        return;
                }
        }
        cout << ma + 3 << '\n';
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
