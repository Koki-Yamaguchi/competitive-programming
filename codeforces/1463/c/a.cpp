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
        int n; cin >> n;
        vector<pair<ll, ll>> tx(n);
        rep(i, n) {
                cin >> tx[i].first >> tx[i].second;
        }
        int i = 0;
        ll pos = 0;
        int ans = 0;
        while (i < n) {
                // cerr << "BEGIN" << endl;
                ll t = tx[i].first;
                ll to = tx[i].second;
                ll cmdt = abs(to - pos);
                ll nxtt = t + cmdt;
                pair<ll, ll> r = {nxtt, -1e17};
                int p = lower_bound(all(tx), r) - tx.begin();
                if (p == i) p ++;
                ll dx = (to - pos < 0 ? -1 : 1);
                ll restcmdt = cmdt;
                for (int s = i; s < p; s ++) {
                        ll dt = (s == n - 1 ? (ll) 1e10 : tx[s + 1].first) - tx[s].first;
                        restcmdt -= dt;
                        ll nxtpos = (restcmdt <= 0 ? to : pos + dx * dt);
                        if (pos <= nxtpos) {
                                if (pos <= tx[s].second && tx[s].second <= nxtpos) {
                                        ans ++;
                                }
                        } else {
                                if (nxtpos <= tx[s].second && tx[s].second <= pos) {
                                        ans ++;
                                }
                        }
                        pos = nxtpos;

                }
                i = p;
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
