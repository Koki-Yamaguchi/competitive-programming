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
        ll x, y, ax, ay, bx, by;
        cin >> x >> y >> ax >> ay >> bx >> by;
        vector<pair<ll, ll>> ps = {{x, y}};
        while (x * ax + bx <= 1e17 && y * ay + by <= 1e17) {
                x = x * ax + bx;
                y = y * ay + by;
                ps.emplace_back(x, y);
        }
        int n = ps.size();
        assert(n <= 80);
        ll t;
        cin >> x >> y >> t;
        int ans = 0;
        rep(i, ps.size()) {
                ll curx = x;
                ll cury = y;
                int res = 0;
                ll rest = t;
                int curi = i;
                while (curi >= 0) {
                        ll d0 = abs(curx - ps[curi].first);
                        ll d1 = abs(cury - ps[curi].second);
                        if (d0 > rest) {
                                rest = 0;
                                break;
                        }
                        rest -= d0;
                        if (d1 > rest) {
                                rest = 0;
                                break;
                        }
                        rest -= d1;
                        res ++;
                        curx = ps[curi].first;
                        cury = ps[curi].second;
                        curi --;
                }
                if (rest == 0) {
                        ans = max(ans, res);
                        continue;
                }
                curi = i + 1;
                while (curi < n) {
                        ll d0 = abs(curx - ps[curi].first);
                        ll d1 = abs(cury - ps[curi].second);
                        if (d0 > rest) {
                                rest = 0;
                                break;
                        }
                        rest -= d0;
                        if (d1 > rest) {
                                rest = 0;
                                break;
                        }
                        rest -= d1;
                        res ++;
                        curx = ps[curi].first;
                        cury = ps[curi].second;
                        curi ++;
                }
                ans = max(ans, res);
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
