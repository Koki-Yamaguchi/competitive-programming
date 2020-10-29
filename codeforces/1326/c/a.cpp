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


const int MOD = 998244353;
void solve() {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        rep(i, n) {
                cin >> a[i].first;
                a[i].second = i;
        }
        sort(rall(a));
        ll ans = 0;
        vector<bool> top(n);
        rep(i, k) {
                ans += a[i].first;
                top[a[i].second] = true;
        }
        // dump(ans);
        int prev = -1;
        ll way = 1;
        rep(i, n) {
                if (top[i]) {
                        if (prev != -1) {
                                (way *= (i - prev)) %= MOD;
                        }
                        prev = i;
                }
        }
        cout << ans << " " << way << '\n';
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
