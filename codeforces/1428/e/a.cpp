#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        priority_queue<int> que;
        rep(i, n) {
                que.push(a[i]);
        }
        k = k - n;
        while (k --) {
                auto v = que.top(); que.pop();
                auto l = v / 2;
                auto r = v - l;
                que.push(l);
                que.push(r);
        }
        ll ans = 0;
        while (not que.empty()) {
                auto v = que.top(); que.pop();
                ans += (ll) v * v;
        }
        cout << ans << '\n';
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
