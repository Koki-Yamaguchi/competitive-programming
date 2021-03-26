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

void solve() {
        ll k, l, r, t, x, y;
        cin >> k >> l >> r >> t >> x >> y;
        ll c = k - l;
        r -= l;
        if (y > r) {
                ll cnt = c / x;
                if (t > cnt) {
                        cout << "No\n";
                } else {
                        cout << "Yes\n";
                }
                return;
        }
        bool ok = true;
        // r - y >= 0
        while (true) {
                if (c + y <= r) {
                        c += y;
                }

                ll xc = ((c - (r - y)) + x - 1) / x;
                if (xc && c - xc * x >= 0) {
                        c -= xc * x;
                        t -= xc;
                        if (t <= 0) break;
                } else {
                        if (c - x < 0) {
                                ok = false;
                                break;
                        }
                        c -= x;
                        t --;
                        if (t <= 0) break;
                }
        }
        cout << (ok ? "Yes\n" : "No\n");
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
