#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long n;
        cin >> n;
        long long x, m;
        cin >> x >> m;
        vector<long long> res(m + 1);
        set<int> app;
        vector<int> pos(m + 1);
        int k = -1, l = -1;
        rep(i, m + 1) {
                res[i] = x;
                if (app.count(x) && k == -1) {
                        k = pos[x];
                        l = i - pos[x];
                }
                pos[x] = i;
                app.insert(x);
                (x *= x) %= m;
        }
        long long cycle = 0;
        for (int i = k; i < k + l; i ++) {
                cycle += res[i];
        }
        long long ans = 0;
        rep(i, k) {
                ans += res[i];
        }
        vector<long long> add(l);
        for (int i = k; i < k + l; i ++) {
                add[i - k] += (i > k ? add[i - k - 1] : 0) + res[i];
        }
        ans += ((n - k) / l) * cycle + ((n - k) % l != 0 ? add[(n - k) % l - 1] : 0);
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
