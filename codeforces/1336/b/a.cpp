#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n = 3;
        vector<int> ns(n);
        rep(i, n) {
                cin >> ns[i];
        }
        vector<vector<ll>> val(n);
        set<ll> used;
        vector<ll> uval;
        rep(i, n) {
                val[i].resize(ns[i]);
                rep(j, ns[i]) {
                        cin >> val[i][j];
                        if (used.count(val[i][j]) == 0) {
                                used.insert(val[i][j]);
                                uval.push_back(val[i][j]);
                        }
                }
        }
        sort(all(uval));
        rep(i, 3) {
                sort(all(val[i]));
        }
        vector<int> p(3);
        ll ans = 5e18;
        for (auto uv : uval) {
                rep(i, 3) {
                        while (p[i] < ns[i] && val[i][p[i]] <= uv) {
                                p[i] ++;
                        }
                }
                for (int d0 = -1; d0 <= 0; d0 ++) {
                        for (int d1 = -1; d1 <= 0; d1 ++) {
                                for (int d2 = -1; d2 <= 0; d2 ++) {
                                        int i0 = p[0] + d0;
                                        int i1 = p[1] + d1;
                                        int i2 = p[2] + d2;
                                        if (0 <= i0 && i0 < ns[0] && 0 <= i1 && i1 < ns[1] && 0 <= i2 && i2 < ns[2]) {
                                                ll res = 0;
                                                res += (val[0][i0] - val[1][i1]) * (val[0][i0] - val[1][i1]);
                                                res += (val[1][i1] - val[2][i2]) * (val[1][i1] - val[2][i2]);
                                                res += (val[2][i2] - val[0][i0]) * (val[2][i2] - val[0][i0]);
                                                ans = min(ans, res);
                                        }
                                }
                        }
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
