#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
        int n;
        cin >> n;
        long long ans = 0;
        long long acc = 0;
        rep(i, n) {
                int a;
                cin >> a;
                (ans += acc * a) %= MOD;
                (acc += a) %= MOD;
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
