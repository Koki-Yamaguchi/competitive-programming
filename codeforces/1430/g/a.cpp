#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
using ll = long long;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<ll, ll>>> g(n), rg(n);
        rep(i, m) {
                ll a, b, c;
                cin >> a >> b >> c;
                a --, b --;
                g[a].emplace_back(b, c);
                rg[b].emplace_back(a, c);
        }
        vector<vector<ll>> dp(n, vector<ll> (n, 1e9));
        vector<vector<vector<pair<ll, ll>>>> prev(n, vector<vector<pair<ll, ll>>> (n));
        function<void (ll, ll)> calc = [&](ll u, ll p) {
                if (dp[u][p] != 1e9) return;
                if (rg[u].size() == 0) {
                        rep(i, n) {
                                dp[u][i] = 0;
                        }
                        return;
                }
                rep(up, n) {
                        ll res = 0;
                        for (auto e : rg[u]) {
                                ll v = e.first;
                                ll c = e.second;
                                ll mi = 1e9;
                                ll vpp = -1;
                                rep(vp, n) {
                                        if (vp < up) {
                                                calc(v, vp);
                                                ll nw = dp[v][vp] + (up - vp) * c;
                                                if (mi > nw) {
                                                        mi = nw;
                                                        vpp = vp;
                                                }
                                        }
                                }
                                prev[u][up].emplace_back(v, up - vpp);
                                res += mi;
                        }
                        if (res < 1e9) {
                                dp[u][up] = res;
                        }
                }
        };
        rep(i, n) {
                rep(j, n) {
                        calc(i, j);
                }
        }
        ll ans = 0;
        rep(i, n) {
                cerr << "i = " << i << endl;
                rep(j, n) {
                        cerr << dp[i][j] << " ";
                }
                cerr << endl;
        }
        rep(i, n) {
                if (g[i].size() == 0) {
                        int p = *min_element(dp[i].begin(), dp[i].end()) - dp.begin();
                        kkkkkkkkkkkkkkkkkkkkk
                }
        }
        cerr << "ans = " << ans << endl;
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
