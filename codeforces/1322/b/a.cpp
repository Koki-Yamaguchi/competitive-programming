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
        int n; cin >> n;
        vector<ll> b(n);
        rep(i, n) {
                cin >> b[i];
        }
        int ans = 0;
        rep(k, 30) {
                vector<int> a(n);
                rep(i, n) {
                        a[i] = b[i] % (1 << (k + 1));
                }
                sort(all(a));
                ll cnt = 0;
                rep(i, n) {
                        // [2^k - a_i, 2^(k + 1) - 1 - a_i]
                        {
                                int l = (1 << k) - a[i];
                                int r = (1 << (k + 1)) - 1 - a[i];
                                int li = lower_bound(all(a), l) - a.begin();
                                int ri = upper_bound(all(a), r) - a.begin();
                                int add = ri - li - (li <= i && i < ri ? 1 : 0);
                                cnt += add;
                        }
                        // [2^(k + 1) + 2^k - a_i, 2^(k + 2) - 2 - a_i]
                        {
                                int l = (1 << (k + 1)) + (1 << k) - a[i];
                                int r = (1 << (k + 2)) - 2 - a[i];
                                int li = lower_bound(all(a), l) - a.begin();
                                int ri = upper_bound(all(a), r) - a.begin();
                                int add = ri - li - (li <= i && i < ri ? 1 : 0);
                                cnt += add;
                        }
                }
                cnt /= 2;
                if (cnt & 1) {
                        ans |= 1 << k;
                }
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
