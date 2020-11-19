#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p) {
        os << p.first << " " << p.second;
        return os;
}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

const int MOD = 998244353;
const int N = 500001;
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
        int n;
        cin >> n;
        ll sum0 = 0, sum1 = 1;
        ll cur = 0;
        rep(i, n) {
                ll nxt = 0;
                if (i & 1) {
                        nxt = sum0;
                        (sum1 += nxt) %= MOD;
                } else {
                        nxt = sum1;
                        (sum0 += nxt) %= MOD;
                }
                swap(cur, nxt);
        }
        rep(i, n) {
                (cur *= inv[2]) %= MOD;
        }
        cout << cur << '\n';
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
