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
        x ++;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] ++;
        }
        vector<vector<int>> dp(502, vector<int> (502, 1e9 + 5)); // x, last
        dp[x][0] = 0;
        rep(i, n) {
                vector<vector<int>> nxt(502, vector<int> (502, 1e9 + 5)); // x, last
                for (int j = 0; j < 502; j ++) {
                        for (int k = 0; k < 502; k ++) {
                                if (a[i] >= k) {
                                        nxt[j][a[i]] = min(nxt[j][a[i]], dp[j][k]); // do nothing
                                }
                                if (a[i] > j && j >= k) {
                                        nxt[a[i]][j] = min(nxt[a[i]][j], dp[j][k] + 1);
                                }
                        }
                }
                /*
                rep(j, 10) {
                        rep(k, 10) {
                                printf("nxt[%d][%d] = %d\n", j, k, nxt[j][k]);
                        }
                }
                */
                swap(dp, nxt);
        }
        int ans = 1e9 + 5;
        rep(i, 502) {
                rep(j, 502) {
                        if (dp[i][j] < (1 << 30)) {
                                ans = min(ans, dp[i][j]);
                        }
                }
        }
        if (ans == (int) (1e9 + 5)) {
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
