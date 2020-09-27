#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        map<int, int> app;
        vector<int> nxt(n);
        for (int i = n - 1; i >= 0; i --) {
                if (app.count(a[i])) {
                        nxt[i] = app[a[i]];
                        app[a[i]] = i;
                } else {
                        nxt[i] = n;
                        app[a[i]] = i;
                }
        }
        set<int> app2;
        map<int, int> ma;
        rep(i, n) {
                if (app2.count(a[i]) == 0) {
                        ma[a[i]] = i + 1;
                        app2.insert(a[i]);
                }
                ma[a[i]] = max(ma[a[i]], nxt[i] - i);
        }
        vector<pair<int, int>> v;
        for (auto it : ma) {
                v.push_back(it);
        }

        sort(v.begin(), v.end());
        vector<int> ans(n, -1);
        int mi = 1e9;
        rep(i, v.size()) {
                if (mi > v[i].second - 1) {
                        ans[v[i].second - 1] = v[i].first;
                        mi = v[i].second - 1;
                }
        }
        rep(i, n) if (i) {
                if (ans[i] == -1 && ans[i - 1] != -1) {
                        ans[i] = ans[i - 1];
                }
        }
        rep(i, n) {
                cout << ans[i] << " \n"[i == n - 1];
        }
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
