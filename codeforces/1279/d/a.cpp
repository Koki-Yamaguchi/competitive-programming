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

long long Inv(long long a) {
        long long res = 1;
        long long n = MOD - 2;
        while (n > 0) {
                if (n & 1) res = res * a % MOD;
                a = a * a % MOD;
                n >>= 1;
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        int maa = 1e6 + 10;
        vector<int> cnt(maa);
        rep(i, n) {
                int c;
                cin >> c;
                a[i].resize(c);
                rep(j, c) {
                        cin >> a[i][j];
                        cnt[a[i][j]] ++;
                }
        }
        ll ans = 0;
        rep(i, n) {
                int c = a[i].size();
                rep(j, c) {
                        (ans += cnt[a[i][j]] * Inv(n) % MOD * Inv(n) % MOD * Inv(c) % MOD) %= MOD;
                }
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
