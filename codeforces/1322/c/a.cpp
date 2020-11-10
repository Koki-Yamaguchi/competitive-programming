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

const ll mod0 = 1e9 + 7;

long long gcd(long long a, long long b) {
        while (b) {
                a %= b;
                swap(a, b);
        }
        return a;
}

void solve() {
        mt19937 rndm(time(0));
        int n, m;
        cin >> n >> m;
        vector<ll> c(n);
        rep(i, n) {
                cin >> c[i];
        }
        vector<vector<int>> g(n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[b].push_back(a);
        }
        vector<ll> hs0(n);
        vector<ll> rnd0(n);
        rep(i, n) {
                rnd0[i] = rndm() % mod0;
        }
        rep(i, n) {
                for (int j : g[i]) {
                        (hs0[i] += rnd0[j]) %= mod0;
                }
        }
        map<ll, vector<int>> v;
        rep(i, n) {
                if (hs0[i] != 0) {
                        v[hs0[i]].push_back(i);
                }
        }
        ll ans = 0;
        for (auto it : v) {
                ll s = 0;
                for (auto itit : it.second) {
                        s += c[itit];
                }
                ans = gcd(ans, s);
        }
        cout << ans << '\n';
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
