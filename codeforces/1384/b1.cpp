#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n);
        rep(i, n) {
                cin >> d[i];
        }
        vector<int> p(2 * k);
        rep(i, k + 1) {
                p[i] = i;
        }
        for (int i = k + 1; i < 2 * k; i ++) {
                p[i] = 2 * k - i;
        }
        // rep(i, 2 * k) cerr << p[i] << " "; cerr << endl;
        auto dep = [&](int t, int x) {
                if (x < 1 || x > n) {
                        return (int) -10000000;
                }
                return d[x - 1] + p[t % (2 * k)];
        };
        const int mat = n * n + 100;
        vector<vector<bool>> dp(n + 2, vector<bool> (mat));
        rep(i, mat) {
                dp[0][i] = true;
        }
        rep(x, n + 1) {
                rep(t, mat - 1) {
                        // move
                        if (dp[x][t] && dep(t + 1, x + 1) <= l) {
                                dp[x + 1][t + 1] = true;
                        }
                        // stay
                        if (dp[x][t] && dep(t + 1, x) <= l) {
                                dp[x][t + 1] = true;
                        }
                }
        }
        bool ok = false;
        rep(i, mat) {
                if (dp[n + 1][i]) {
                        ok = true;
                }
        }
        puts(ok ? "Yes" : "No");
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
