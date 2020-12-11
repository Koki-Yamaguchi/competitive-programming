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
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        rep(i, h) {
                cin >> s[i];
        }
        vector<vector<int>> ma(h, vector<int> (w));
        rep(i, h) {
                int cur = 0;
                rep(j, w) {
                        if (s[i][j] == '.') {
                                cur = 0;
                                continue;
                        }
                        cur ++;
                        if (i == 0 || j == 0 || (i && j && (s[i - 1][j - 1] == '.'))) {
                                ma[i][j] = 1;
                                continue;
                        }
                        int l = min(ma[i - 1][j - 1] + 1, (cur + 1) / 2);
                        ma[i][j] = l;
                }
        }
        ll ans = 0;
        rep(i, h) rep(j, w) ans += ma[i][j];
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
