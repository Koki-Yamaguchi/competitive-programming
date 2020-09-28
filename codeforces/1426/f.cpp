#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

const int MOD = 1e9 + 7;

long long ModPow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % MOD;
                x = x * x % MOD;
                n >>= 1;
        }
        return res;
}

long long f(const string &s, char x, char y, char z, int k) {
        long long ans = 0;
        int n = s.size();
        int zcnt = 0;
        vector<long long> yzcnt(n);
        for (int i = n - 1; i >= 0; i --) {
                yzcnt[i] = (i < n - 1 ? yzcnt[i + 1] : 0);
                if (s[i] == y) {
                        yzcnt[i] += zcnt;
                }
                zcnt += (s[i] == z);
        }
        rep(i, n) {
                if (s[i] == x) {
                        (ans += (long long) (i < n - 1 ? yzcnt[i + 1] : 0)) %= MOD;
                }
        }
        int c = (x == '?') + (y == '?') + (z == '?');
        (ans *= ModPow(3, k - c)) %= MOD;
        return ans;
}

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k = 0;
        rep(i, n) {
                k += s[i] == '?';
        }
        long long ans = 0;
        (ans += f(s, 'a', 'b', 'c', k)) %= MOD;
        (ans += f(s, '?', 'b', 'c', k)) %= MOD;
        (ans += f(s, 'a', '?', 'c', k)) %= MOD;
        (ans += f(s, 'a', 'b', '?', k)) %= MOD;
        (ans += f(s, '?', '?', 'c', k)) %= MOD;
        (ans += f(s, '?', 'b', '?', k)) %= MOD;
        (ans += f(s, 'a', '?', '?', k)) %= MOD;
        (ans += f(s, '?', '?', '?', k)) %= MOD;
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
