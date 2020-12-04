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
        ll d = 0;
        ll ans = 0;
        rep(i, n) {
                ll c = -1e18;
                if (i && i < n - 1) {
                        c = abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]);
                } else if (i) {
                        c = abs(a[i] - a[i - 1]);
                } else {
                        c = abs(a[i] - a[i + 1]);
                }
                if (i) {
                        ans += abs(a[i - 1] - a[i]);
                }
                d = max(d, c);
        }
        cout << ans - d << '\n';
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
