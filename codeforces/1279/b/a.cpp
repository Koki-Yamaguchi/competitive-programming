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
        int n, s;
        cin >> n >> s;
        vector<ll> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        ll sum = 0;
        ll ma = -1;
        int mai = -1;
        bool f = false;
        rep(i, n) {
                sum += a[i];
                if (ma < a[i]) {
                        ma = max(ma, a[i]);
                        mai = i;
                }
                if (sum > s) {
                        f = true;
                        break;
                }
        }
        if (not f) mai = -1;
        cout << mai + 1 << '\n';
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
