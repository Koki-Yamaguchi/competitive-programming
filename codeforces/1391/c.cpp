#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long ModPow(long long x, long long n, long long m) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % m;
                x = x * x % m;
                n >>= 1;
        }
        return res;
}

const int MOD = 1e9 + 7;

const int N = 1000005;
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

void solve() {
        init();
        int n;
        cin >> n;
        cout << (((fact[n] - ModPow(2, n - 1, MOD)) + MOD) % MOD) << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
