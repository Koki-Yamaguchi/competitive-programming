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
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        vector<pair<int, long double>> qs(m);
        rep(i, m) {
                cin >> qs[i].first >> qs[i].second;
                qs[i].first --;
        }
        int p = -1;
        for (int i = n - 1; i >= 0; i --) {
                if (a[i] != i) {
                        p = i;
                        break;
                }
        }
        long double ans = 1.0;
        long double all_fail = 1.0;
        if (p != -1) {
                rep(i, m) {
                        if (qs[i].first >= p) {
                                all_fail *= 1.0 - qs[i].second;
                        }
                }
                ans -= all_fail;
        }
        cout << fixed << setprecision(10) << ans << '\n';
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
