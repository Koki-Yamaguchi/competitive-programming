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
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        const int maa = 2e5 + 5;
        vector<int> has(maa);
        rep(i, n) {
                has[a[i]] ++;
                if (has[a[i]] > 3) has[a[i]] = 3;
        }
        vector<int> dp(maa, 1e9);
        dp[0] = 0;
        rep(i, maa) {
                if (i - 1 >= 0) dp[i] = min(dp[i], dp[i - 1] + (has[i] > 0));
                if (i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + (has[i] > 0 || has[i - 1] > 0));
                if (i - 3 >= 0) dp[i] = min(dp[i], dp[i - 3] + (has[i] > 0 || has[i - 1] > 0 || has[i - 2] > 0));
        }
        int ma = 0;
        vector<bool> used(maa);
        rep(i, maa) {
                for (int j = -1; j <= 1; j ++) {
                        if (has[i]) {
                                if (not used[i + j]) {
                                        used[i + j] = true;
                                        has[i] --;
                                        ma ++;
                                }
                        }
                }
        }
        cout << dp[maa - 1] << ' ' << ma << '\n';
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
