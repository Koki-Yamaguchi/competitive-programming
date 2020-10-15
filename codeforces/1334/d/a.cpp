#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        ll n, l, r;
        cin >> n >> l >> r;
        ll tot = 0;
        ll x = 2 * n - 2;
        ll cur = 1;
        bool f = false;
        vector<ll> ans;
        while (x) {
                if (tot + x >= l) {
                        f = true;
                }
                if (tot > r) {
                        f =  false;
                }
                if (f) {
                        ll p = cur + 1;
                        for (int i = 0; i < x; i ++) {
                                ll add;
                                if (i % 2 == 0) {
                                        add = cur;
                                } else {
                                        add = p;
                                        p ++;
                                }
                                if (l <= tot + i + 1 && tot + i + 1 <= r) {
                                        ans.push_back(add);
                                }
                        }
                }
                cur ++;
                tot += x;
                x -= 2;
        }
        if (tot + 1 == r) {
                ans.push_back(1);
        }
        rep(i, ans.size()) {
                cout << ans[i] << " \n"[i + 1 == ans.size()];
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
