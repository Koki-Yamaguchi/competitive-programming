#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

const int MOD = 1e9 + 7; 

long long ModPow(long long x, long long n, long long m = MOD) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % m;
                x = x * x % m;
                n >>= 1;
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        long long z = ModPow(10, n) - ModPow(9, n);
        long long ei = ModPow(10, n) - ModPow(8, n);
        cout << ((2ll * z % MOD - ei) % MOD + MOD) % MOD << '\n';
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
