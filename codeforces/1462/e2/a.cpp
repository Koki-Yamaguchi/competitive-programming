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

const int MOD = 1e9 + 7;

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
long long C(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        return fact[n] * invfact[n - r] % MOD * invfact[r] % MOD;
}

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        vector<pair<int, int>> cnt;
        rep(i, n) {
                if (cnt.empty() || cnt.back().first != a[i]) {
                        cnt.emplace_back(a[i], 1);
                } else {
                        cnt.back().second ++;
                }
        }
        int sz = cnt.size();
        vector<int> acc(sz); acc[0] = cnt[0].second;
        rep(i, sz) if (i) {
                acc[i] = acc[i - 1] + cnt[i].second;
        }
        ll ans = 0;
        rep(i, sz) {
                int v = cnt[i].first;
                int c = cnt[i].second;
                pair<int, int> r = {v + k, 1e9};
                int pos = upper_bound(all(cnt), r) - cnt.begin();
                pos --;
                int free = acc[pos] - acc[i];
                for (int take = 1; take <= min(c, m); take ++) {
                        (ans += C(c, take) * C(free, m - take)) %= MOD;
                }
        }
        cout << ans << '\n';
}

int main() {
        init();
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
