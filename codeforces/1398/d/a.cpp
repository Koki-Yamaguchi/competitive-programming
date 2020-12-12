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

void chmax(ll &a, ll b) {
        a = max(a, b);
}

void solve() {
        vector<int> sz(3);
        rep(i, 3) {
                cin >> sz[i];
        }
        vector<vector<int>> val(3);
        rep(i, 3) {
                val[i].resize(sz[i]);
                rep(j, sz[i]) {
                        cin >> val[i][j];
                }
        }
        rep(i, 3) {
                sort(rall(val[i]));
        }
        vector<vector<vector<ll>>> dp(sz[0] + 1, vector<vector<ll>> (sz[1] + 1, vector<ll> (sz[2] + 1)));
        rep(i, sz[0] + 1) { rep(j, sz[1] + 1) {
                        rep(k, sz[2] + 1) {
                                auto from = dp[i][j][k];
                                if (i < sz[0] && j < sz[1]) chmax(dp[i + 1][j + 1][k], from + val[0][i] * val[1][j]);
                                if (j < sz[1] && k < sz[2]) chmax(dp[i][j + 1][k + 1], from + val[1][j] * val[2][k]);
                                if (k < sz[2] && i < sz[0]) chmax(dp[i + 1][j][k + 1], from + val[2][k] * val[0][i]);
                        }
                }
        }
        ll ans = 0;
        rep(i, sz[0] + 1) rep(j, sz[1] + 1) rep(k, sz[2] + 1) chmax(ans, dp[i][j][k]);
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
