#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

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

const int N = 5000001;
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
        int n, m;
        cin >> n >> m;
        ll ans = 0;
        for (int i = 2; i <= m; i ++) {
                (ans += (i - 1) * C(i - 2, n - 3) % MOD * ModPow(2, n - 3)) %= MOD;
        }
        cout << ans << '\n';
}

int main() {
        init();
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
