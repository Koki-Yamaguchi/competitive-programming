#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

void solve() {
        int n;
        cin >> n;
        vector<int> t(n);
        rep(i, n) {
                cin >> t[i];
        }
        sort(all(t));
        int mat = n + 250;
        vector<vector<int>> dp(n + 1, vector<int> (mat + 1, 1e9));
        rep(i, mat + 1) {
                dp[0][i] = 0;
        }
        rep(i, n) {
                for (int j = 0; j <= mat; j ++) {
                        for (int k = j + 1; k <= mat; k ++) {
                                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + abs(k - t[i]));
                        }
                }
        }
        rep(i, n) {
                // dump(dp[i]);
        }
        cout << *min_element(all(dp[n])) << '\n';
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
