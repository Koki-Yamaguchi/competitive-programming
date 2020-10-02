#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<pair<long long, long long>> fs(m);
        rep(i, m) {
                cin >> fs[i].first >> fs[i].second;
        }
        sort(fs.rbegin(), fs.rend());
        // no duplication
        long long ans = 0;
        if (n <= m) {
                rep(i, n) {
                        ans += fs[i].first;
                }
        }
        // one duplication
        if (n >= 2) {
                vector<long long> acc(m);
                acc[0] = fs[0].first;
                rep(i, m) if (i) {
                        acc[i] = acc[i - 1] + fs[i].first;
                }
                rep(i, m) {
                        fs[i].first = -fs[i].first;
                }
                rep(i, m) {
                        long long res = 0;
                        res += -fs[i].first + fs[i].second;
                        pair<long long, long long> bbb = make_pair(-fs[i].second, -1e18);
                        int idx = lower_bound(fs.begin(), fs.end(), bbb) - fs.begin();
                        res += (idx > 0 ? acc[idx - 1] : 0);
                        if (i < idx) {
                                res -= -fs[i].first;
                                idx --;
                        }
                        res += (long long) max(0ll, (long long) n - idx - 2) * fs[i].second;
                        // cerr << "res =" << res << endl;
                        ans = max(ans, res);
                }
        }
        cout << ans << '\n';
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
