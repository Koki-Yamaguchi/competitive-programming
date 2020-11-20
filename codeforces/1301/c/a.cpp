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
        int n, m;
        cin >> n >> m;
        int val = n - m;
        int div = m + 1;
        int large_cnt = ((val % div) ? (val % div) : div);
        int small_cnt = div - large_cnt;
        int large = (val + div - 1) / div;
        int small = large - 1;
        ll ans = 0;
        ans += (ll) large_cnt * large * (large + 1) / 2;
        ans += (ll) small_cnt * small * (small + 1) / 2;
        ans = (ll) n * (n + 1) / 2 - ans;
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
