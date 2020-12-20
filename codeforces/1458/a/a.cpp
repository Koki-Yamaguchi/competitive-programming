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
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, m) {
                cin >> b[i];
        }
        sort(rall(a));
        ll g = 0;
        rep(i, n - 1) {
                g = gcd(g, a[i] - a[i + 1]);
        }
        rep(i, m) {
                cout << gcd(g, a.back() + b[i]) << " \n"[i == m - 1];
        }
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
