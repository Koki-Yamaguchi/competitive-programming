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
        int n;
        ll t;
        cin >> n >> t;
        vector<ll> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int m0 = n / 2;
        int m1 = n - m0;
        vector<ll> val0, val1;
        rep(s, 1 << m0) {
                ll sum = 0;
                rep(i, m0) {
                        if ((s >> i) & 1) {
                                sum += a[i];
                        }
                }
                val0.push_back(sum);
        }
        rep(s, 1 << m1) {
                ll sum = 0;
                rep(i, m1) {
                        if ((s >> i) & 1) {
                                sum += a[i + m0];
                        }
                }
                val1.push_back(sum);
        }
        sort(all(val1));
        ll ans = 0;
        rep(i, val0.size()) {
                if (val0[i] > t) continue;
                ll r = t - val0[i];
                int p = upper_bound(all(val1), r) - val1.begin();
                p --;
                if (p >= 0) {
                        ans = max(ans, val0[i] + val1[p]);
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
