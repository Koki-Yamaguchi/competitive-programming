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
        int n, p, k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;
        vector<int> acc(n);
        acc[n - 1] = (s[n - 1] == '0');
        for (int i = n - 2; i >= 0; i --) {
                acc[i] = (i + k < n ? acc[i + k] : 0) + (s[i] == '0');
        }
        ll ans = 1e18;
        for (int yc = 0; yc <= n - p; yc ++) {
                int idx = yc + p - 1;
                ans = min(ans, (ll) acc[idx] * x + (ll) yc * y);
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
