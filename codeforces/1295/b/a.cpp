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
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        vector<int> acc(n);
        acc[0] = (s[0] == '0' ? 1 : -1);
        ll ans = 0;
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] + (s[i] == '0' ? 1 : -1);
        }
        int d = acc[n - 1];
        rep(i, n) {
                ans += (acc[i] == x);
        }
        if (d > 0) {
                rep(i, n) {
                        int need = x - acc[i];
                        if (need > 0 && need % d == 0) {
                                ans ++;
                        }
                }
        } else if (d < 0) {
                d *= -1;
                rep(i, n) {
                        int need = acc[i] - x;
                        if (need > 0 && need % d == 0) {
                                ans ++;
                        }
                }
        }
        if (x == 0) {
                ans ++;
        }
        if (d == 0 && ans > 0) {
                ans = -1;
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
