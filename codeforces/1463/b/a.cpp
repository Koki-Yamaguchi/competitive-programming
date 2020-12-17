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
        ll s0 = 0;
        ll s1 = 0;
        rep(i, n) {
                cin >> a[i];
                if (i & 1) {
                        s0 += a[i];
                } else {
                        s1 += a[i];
                }
        }
        bool use_o = s0 > s1;
        vector<int> b(n);
        rep(i, n) {
                if ((use_o && (i & 1)) || (not use_o && i % 2 == 0)) {
                        b[i] = a[i];
                } else {
                        b[i] = 1;
                }
        }
        cout << b << '\n';
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
