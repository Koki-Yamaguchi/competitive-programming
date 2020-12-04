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

long long gcd(long long a, long long b) {
        while (b) {
                a %= b;
                swap(a, b);
        }
        return a;
}

template<class T>
vector<pair<T, int>> factorize(T n) {
        assert(n > 1);
        vector<pair<T, int>> res;
        for (T i = 2; i * i <= n; i ++) {
                if (n % i == 0) {
                        int c = 0;
                        while (n % i == 0) {
                                n /= i;
                                c ++;
                        }
                        res.emplace_back(i, c);
                }
        }
        if (n > 1) {
                res.emplace_back(n, 1);
        }
        return res;
}

// 1 以上 v 以下であって x と素であるものの数
ll f(ll v, ll x) {
        auto fac = factorize(x);
        vector<ll> ps;
        rep(i, fac.size()) {
                ps.push_back(fac[i].first);
        }
        int m = ps.size();
        ll res = 0;
        for (int s = 1; s < (1 << m); s ++) {
                int cnt = __builtin_popcount(s);
                ll val = 1;
                rep(i, m) {
                        if ((s >> i) & 1) {
                                val *= ps[i];
                        }
                }
                if (cnt & 1) {
                        res += v / val;
                } else {
                        res -= v / val;
                }
        }
        return v - res;
}

void solve() {
        ll a, m;
        cin >> a >> m;
        ll g = gcd(a, m);
        a /= g;
        m /= g;
        // a <= k < a + m であって m と素であるものの数
        cout << f(a + m - 1, m) - f(a - 1, m) << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
