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
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>> (m + 1, {-1, -1}));
        rep(i, n) {
                rep(j, m) {
                        int &ref = dp[i + 1][j + 1];
                        if (s[i] == t[j]) {
                                ref = max(ref, dp[i][j] + 1);
                                prev[i + 1][j + 1] = make_pair(i, j);
                        } else {
                                ref = max(ref, dp[i + 1][j]);
                                ref = max(ref, dp[i][j + 1]);
                                if (dp[i + 1][j] < dp[i][j + 1]) {
                                        prev[i + 1][j + 1] = prev[i][j + 1];
                                } else {
                                        prev[i + 1][j + 1] = prev[i + 1][j];
                                }
                        }
                }
        }
        string ans;
        int ni = n, mi = m;
        while (true) {
                auto [i, j] = prev[ni][mi];
                if (i == -1) {
                        break;
                }
                assert(s[i] == t[j]);
                ans.push_back(s[i]);
                ni = i;
                mi = j;
        }
        reverse(all(ans));
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
