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

const int inf = 1e9;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        if (n >= 65) {
                cout << 1 << '\n';
                return;
        }
        vector<int> acc(n + 1);
        rep(i, n) {
                acc[i + 1] = acc[i] ^ a[i];
        }
        int ans = inf;
        for (int l = 0; l < n - 1; l ++) {
                for (int m = l + 1; m < n; m ++) {
                        for (int r = m + 1; r < n + 1; r ++) {
                                int left = acc[m] ^ acc[l];
                                int right = acc[r] ^ acc[m];
                                if (left > right) {
                                        ans = min(ans, m - l - 1 + r - m - 1);
                                }
                        }
                }
        }
        if (ans == inf) {
                ans = -1;
        }
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        //int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
