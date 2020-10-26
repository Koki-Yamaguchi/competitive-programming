#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

const int MOD = 1e9 + 7;

const int N = 10001;
long long fact[N];
long long invfact[N];
long long inv[N];
void init() {
        fact[0] = fact[1] = 1;
        for (int i = 2; i < N; i ++) fact[i] = fact[i - 1] * i % MOD;
        inv[1] = 1;
        for (int i = 2; i < N; i ++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        invfact[0] = invfact[1] = 1;
        for (int i = 2; i < N; i ++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}
long long C(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        return fact[n] * invfact[n - r] % MOD * invfact[r] % MOD;
}

void solve() {
        init();
        int n, x, pos;
        cin >> n >> x >> pos;
        int lb = 0, ub = n;
        int less_need = 0, more_need = 0;
        while (lb < ub) {
                int mid = (lb + ub) / 2;
                if (mid <= pos) {
                        lb = mid + 1;
                        less_need ++;
                } else {
                        ub = mid;
                        more_need ++;
                }
        }
        assert(lb - 1 == pos);
        less_need --;

        int less = x - 1;
        int more = n - x;
        if (less < less_need || more < more_need) {
                cout << 0 << '\n';
                return;
        }
        ll ans = 1;
        (ans *= C(less, less_need) * fact[less_need] % MOD) %= MOD;
        (ans *= C(more, more_need) * fact[more_need] % MOD) %= MOD;
        (ans *= fact[n - less_need - more_need - 1]) %= MOD;
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
