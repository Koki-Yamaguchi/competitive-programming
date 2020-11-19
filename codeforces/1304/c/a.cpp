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

struct cus {
        ll t;
        ll l, h;
};

void solve() {
        int n;
        ll m;
        cin >> n >> m;
        vector<cus> c(n);
        rep(i, n) {
                cin >> c[i].t >> c[i].l >> c[i].h;
        }
        sort(all(c), [&](auto a, auto b) {
                return a.t < b.t;
        });
        ll lb = m, ub = m;
        ll curt = 0;
        rep(i, n) {
                ll dt = c[i].t - curt;
                lb -= dt;
                ub += dt;
                ll l = c[i].l;
                ll h = c[i].h;
                if (not (ub < l || h < lb)) {
                        lb = max(l, lb);
                        ub = min(h, ub);
                } else {
                        cout << "NO\n";
                        return;
                }
                curt = c[i].t;
        }
        cout << "YES\n";
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
