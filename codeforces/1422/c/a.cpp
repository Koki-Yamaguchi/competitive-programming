#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

const int MOD = 1e9 + 7;

long long ModPow(long long x, long long n, long long m) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % m;
                x = x * x % m;
                n >>= 1;
        }
        return res;
}

void solve() {
        string s;
        cin >> s;
        int n = s.size();
        reverse(s.begin(), s.end());
        long long sum = 0;
        long long ans = 0;
        vector<long long> take(n + 1);
        take[1] = 1;
        rep(i, n) if (i) {
                (take[i + 1] = take[i] + i + 1) %= MOD;
        }
        rep(i, n) {
                if (i) {
                        if (i == 1) {
                                (sum += ((i - 1) <= 1 ? 1 : (i))) %= MOD;
                        } else {
                                (sum += ModPow(10, i - 1, MOD) * i % MOD) %= MOD;
                        }
                }
                (ans += sum * (s[i] - '0') % MOD) %= MOD;
                (ans += take[n - i - 1] * ((s[i] - '0') % MOD * ModPow(10, i, MOD) % MOD)) %= MOD;
        }
        cout << ans << '\n';
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
