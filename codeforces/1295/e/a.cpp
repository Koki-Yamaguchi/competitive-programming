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
        vector<int> p(n), a(n);
        rep(i, n) {
                cin >> p[i];
        }
        rep(i, n) {
                cin >> a[i];
        }
        ll ans = 0;
        rep(i, n) {
                if (i == 0) {
                        if (p[i] > 1) {
                                ans += a[i];
                        }
                } else {
                        if (p[i] == 1) {
                                ans += a[i];
                        }
                }
        }
        set<int> st;
        vector<bool> ex(n);
        rep(i, n) {
                st.insert(a[i]);
        }
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
