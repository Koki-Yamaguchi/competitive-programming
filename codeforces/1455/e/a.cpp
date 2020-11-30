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

ll slv(const vector<pair<ll, ll>> &ps) {
        int n = 4;
        vector<ll> y, x;
        rep(i, n) {
                x.push_back(ps[i].first);
                y.push_back(ps[i].second);
        }
        sort(all(x));
        sort(all(y));
        ll res = 1e18;
        auto calc = [&](ll by, ll ty, ll lx, ll rx) {
                vector<pair<ll, ll>> sq;
                sq.emplace_back(lx, by);
                sq.emplace_back(lx, ty);
                sq.emplace_back(rx, by);
                sq.emplace_back(rx, ty);
                vector<int> idx = {0, 1, 2, 3};
                ll mind = 1e18;
                do {
                        ll d = 0;
                        rep(i, 4) {
                                d += abs(sq[i].first - ps[idx[i]].first);
                                d += abs(sq[i].second - ps[idx[i]].second);
                        }
                        mind = min(mind, d);
                } while (next_permutation(all(idx)));
                return mind;
        };
        for (int bi = 0; bi < 3; bi ++) {
                for (int ti = bi + 1; ti < 4; ti ++) {
                        ll by = y[bi];
                        ll ty = y[ti];
                        ll len = ty - by;
                        if (len == 0) continue;
                        for (int li = 0; li < 3; li ++) {
                                ll lx = x[li];
                                ll rx = lx + len;
                                res = min(res, calc(by, ty, lx, rx));
                        }
                        for (int ri = 3; ri >= 1; ri --) {
                                ll rx = x[ri];
                                ll lx = rx - len;
                                res = min(res, calc(by, ty, lx, rx));
                        }
                }
        }
        return res;
}

void solve() {
        int n = 4;
        vector<pair<ll, ll>> ps(n);
        rep(i, n) {
                cin >> ps[i].first >> ps[i].second;
        }
        ll ans = 1e18;
        ans = min(ans, slv(ps));
        rep(i, n) {
                swap(ps[i].first, ps[i].second);
        }
        ans = min(ans, slv(ps));
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
