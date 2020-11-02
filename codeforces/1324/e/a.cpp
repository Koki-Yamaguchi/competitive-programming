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
        int n, h, l, r;
        cin >> n >> h >> l >> r;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<int> dp(h, -1e9);
        dp[0] = 0;
        rep(i, n) {
                vector<int> nxt(h, -1e9);
                rep(j, h) {
                        rep(d, 2) {
                                int v = (j + (a[i] - d)) % h;
                                int &ref = nxt[v];
                                bool good = (l <= v && v <= r);
                                ref = max(ref, dp[j] + good);
                        }
                }
                swap(dp, nxt);
        }
        cout << *max_element(all(dp)) << '\n';
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
