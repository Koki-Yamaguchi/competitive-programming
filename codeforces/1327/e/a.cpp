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

void solve() {
        int n;
        cin >> n;
        vector<int> ans;
        for (int k = 1; k <= n; k ++) {
                ll res = 0;
                if (n - k - 2 >= 0) {
                        (res += (n - k - 1) * 10 * 9 * 9 * ModPow(10, n - k - 2)) %= MOD;
                }
                if (n - k - 1 >= 0) {
                        (res += 2 * 10 * 9 * ModPow(10, n - k - 1)) %= MOD;
                }
                if (n == k) {
                        (res += 10) %= MOD;
                }
                ans.push_back(res);
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