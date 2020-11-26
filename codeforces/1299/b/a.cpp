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
        vector<ll> x(n), y(n);
        rep(i, n) {
                cin >> x[i] >> y[i];
        }
        x.push_back(x[0]);
        y.push_back(y[0]);
        if (n & 1) {
                cout << "NO\n";
                return;
        }
        rep(i, n / 2) {
                ll dx0 = x[i + 1] - x[i];
                ll dy0 = y[i + 1] - y[i];
                ll dx1 = x[i + 1 + n / 2] - x[i + n / 2];
                ll dy1 = y[i + 1 + n / 2] - y[i + n / 2];
                if (dx0 * dy1 != dx1 * dy0) {
                        cout << "NO\n";
                        return;
                }
                if (dx0 * dx0 + dy0 * dy0 != dx1 * dx1 + dy1 * dy1) {
                        cout << "NO\n";
                        return;
                }
        }
        cout << "YES\n";
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
