#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        ll y, x;
        cin >> y >> x;
        ll c1, c2, c3, c4, c5, c6;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        vector<pair<ll, pair<ll, ll>>> cand;
        cand.emplace_back(0, make_pair(0, 0));
        if (x >= 0 && y >= 0) {
                cand.emplace_back(y * c1, make_pair(y, y));
                cand.emplace_back(x * c1, make_pair(x, x));
        } else if (x >= 0 && y <= 0) {
                cand.emplace_back(-y * c4, make_pair(y, y));
                cand.emplace_back(x * c1, make_pair(x, x));
        } else if (x <= 0 && y >= 0) {
                cand.emplace_back(y * c1, make_pair(y, y));
                cand.emplace_back(-x * c4, make_pair(x, x));
        } else {
                cand.emplace_back(-y * c4, make_pair(y, y));
                cand.emplace_back(-x * c4, make_pair(x, x));
        }
        ll ans = 2e18;
        for (auto c : cand) {
                ll xc = (x > c.second.first ? c2 : c5) * abs(x - c.second.first);
                ll yc = (y > c.second.second ? c6 : c3) * abs(y - c.second.second);
                ans = min(ans, c.first + xc + yc);
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
