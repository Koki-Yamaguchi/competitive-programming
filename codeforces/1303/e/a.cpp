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
        int ts = t.size();
        vector<vector<int>> nxt(n + 1, vector<int> (26, -1));
        for (int i = n - 1; i >= 0; i --) {
                rep(j, 26) {
                        nxt[i][j] = nxt[i + 1][j];
                }
                nxt[i][s[i] - 'a'] = i + 1;
        }
        bool ok = false;
        rep(m, ts + 1) {
                string t0 = t.substr(0, m);
                string t1 = t.substr(m, ts - m);
                int p = t0.size();
                int q = t1.size();
                vector<vector<int>> dp(p + 1, vector<int> (q + 1, 1 << 30));
                dp[0][0] = 0;
                rep(i, p + 1) {
                        rep(j, q + 1) {
                                if (dp[i][j] != 1 << 30) {
                                        if (i < p && nxt[dp[i][j]][t0[i] - 'a'] != -1) {
                                                dp[i + 1][j] = min(dp[i + 1][j], nxt[dp[i][j]][t0[i] - 'a']);
                                        }
                                        if (j < q && nxt[dp[i][j]][t1[j] - 'a'] != -1) {
                                                dp[i][j + 1] = min(dp[i][j + 1], nxt[dp[i][j]][t1[j] - 'a']);
                                        }
                                }
                        }
                }
                if (dp[p][q] != 1 << 30) {
                        ok = true;
                        break;
                }
        }
        cout << (ok ? "YES\n" : "NO\n");
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
