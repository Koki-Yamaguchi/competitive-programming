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
        vector<vector<int>> a(h, vector<int> (w));
        rep(i, h) {
                rep(j, w) {
                        cin >> a[i][j];
                }
        }
        ll ans = 0;
        rep(c, w) {
                vector<int> col;
                rep(i, h) {
                        col.push_back(a[i][c]);
                }
                int a0 = c + 1;
                vector<int> cnt(h);
                rep(i, h) {
                        if (col[i] % w != a0 % w) {
                                continue;
                        }
                        int target = col[i] / w;
                        if (col[i] % w == 0) target --;
                        if (target >= h) {
                                continue;
                        }
                        int diff = i - target;
                        if (diff < 0) {
                                diff += h;
                        }
                        assert(0 <= diff && diff < h);
                        cnt[diff] ++;
                }
                int res = 1e9;
                rep(i, h) {
                        int r = i + h - cnt[i];
                        res = min(res, r);
                }
                ans += res;
        }
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
