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
        int n;
        cin >> n;
        vector<int> a(n);
        int ma = 0;
        rep(i, n) {
                cin >> a[i];
                ma = max(ma, a[i]);
        }
        bool same = true;
        rep(i, n - 1) {
                if (a[i] != a[i + 1]) {
                        same = false;
                        break;
                }
        }
        if (same) {
                cout << -1 << '\n';
                return;
        }
        rep(i, n) {
                if (a[i] == ma) {
                        if (i > 0 && a[i - 1] < a[i]) {
                                cout << i + 1 << '\n';
                                return;
                        }
                        if (i < n - 1 && a[i + 1] < a[i]) {
                                cout << i + 1 << '\n';
                                return;
                        }
                }
        }
        assert(false);
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
