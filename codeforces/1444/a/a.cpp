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

void solve() {
        ll p, q;
        cin >> p >> q;
        if (p % q != 0) {
                cout << p << '\n';
                return;
        }
        auto f = factorize(q);
        ll mi = 1e18 + 10;
        rep(i, f.size()) {
                ll v = f[i].first;
                ll ppp = p;
                int cnt = 0;
                while (ppp % v == 0) {
                        ppp /= v;
                        cnt ++;
                }
                int c = f[i].second;
                int r = cnt - c + 1;
                ll m = 1;
                while (r --) {
                        m *= v;
                }
                mi = min(mi, m);
        }
        cout << p / mi << '\n';
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
