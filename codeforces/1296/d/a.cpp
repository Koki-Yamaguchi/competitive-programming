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
        ll n, a, b, k;
        cin >> n >> a >> b >> k;
        vector<ll> h(n);
        rep(i, n) {
                cin >> h[i];
        }
        vector<ll> need(n);
        rep(i, n) {
                if (h[i] <= a) {
                        need[i] = 0;
                        continue;
                }
                h[i] -= a;
                h[i] %= (a + b);
                if (1 <= h[i] && h[i] <= b) {
                        need[i] = (h[i] + a - 1) / a;
                } else {
                        need[i] = 0;
                }
        }
        sort(all(need));
        int ans = 0;
        ll used = 0;
        rep(i, n) {
                used += need[i];
                if (used > k) {
                        break;
                }
                ans = i + 1;
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
