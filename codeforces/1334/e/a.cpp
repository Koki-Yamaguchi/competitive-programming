#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

const int MOD = 998244353;

const int N = 1000;
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
        ll d;
        cin >> d;
        /*
        d = 2ll * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 * 31 * 37 * 41;
        cerr << "d = " << d << endl;
        assert(1e14 <= d <= 1e15);
        */
        vector<ll> ds;
        for (ll i = 1; i * i <= d; i ++) {
                if (d % i == 0) {
                        ds.push_back(i);
                        if (i != d / i) {
                                ds.push_back(d / i);
                        }
                }
        }
        sort(all(ds));
        map<ll, ll> mf; // min factors of [1,d]
        for (int i = 1; i < ds.size(); i ++) {
                if (mf.count(ds[i]) == 0) {
                        mf[ds[i]] = ds[i];
                        for (int j = i + 1; j < ds.size(); j ++) {
                                if (mf.count(ds[j]) == 0 && ds[j] % ds[i] == 0) {
                                        mf[ds[j]] = ds[i];
                                }
                        }
                }
        }
        int q;
        cin >> q;
        auto calc = [&](ll v) {
                map<ll, int> primes;
                while (v > 1) {
                        primes[mf[v]] ++;
                        v /= mf[v];
                }
                int tot = 0;
                ll res = 1;
                for (auto it : primes) {
                        tot += it.second;
                        (res *= invfact[it.second]) %= MOD;
                }
                (res *= fact[tot]) %= MOD;
                return res;
        };
        auto gcd = [](ll a, ll b) {
                while (b) {
                        a %= b;
                        swap(a, b);
                }
                return a;
        };
        while (q --) {
                ll u, v;
                cin >> u >> v;
                ll g = gcd(u, v);
                ll ua = calc(u / g);
                ll va = calc(v / g);
                cout << ua * va % MOD << '\n';
        }
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
