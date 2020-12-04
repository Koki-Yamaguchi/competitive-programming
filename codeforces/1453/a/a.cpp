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
        vector<int> a(n), b(m);
        map<int, int> cnt;
        rep(i, n) {
                cin >> a[i];
                cnt[a[i]] ++;
        }
        rep(i, m) {
                cin >> b[i];
                cnt[b[i]] ++;
        }
        ll ans = 0;
        for (auto it : cnt) {
                ans += it.second - 1;
        }
        cout << ans << '\n';
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
