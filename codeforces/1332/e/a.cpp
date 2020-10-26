#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

const int MOD = 998244353;

long long ModPow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % MOD;
                x = x * x % MOD;
                n >>= 1;
        }
        return res;
}

void solve() {
        ll n, m, l, r;
        cin >> n >> m >> l >> r;
        if (n % 2 == 1 && m % 2 == 1) {
                ll ans = ModPow(r - l + 1, n * m);
                cout << ans << '\n';
                return;
        }
        int even = r / 2 - (l - 1) / 2;
        int odd = (r + 1) / 2 - l / 2;
        ll ans = ModPow(odd + even, n * m);
        (ans += ModPow((-odd + even + MOD) % MOD, n * m)) %= MOD;
        (ans *= ModPow(2, MOD - 2)) %= MOD;
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
