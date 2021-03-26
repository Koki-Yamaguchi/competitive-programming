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
        rep(i, n) {
                cin >> a[i];
        }
        int mi = 1e9;
        int val = 0;
        rep(i, n) {
                mi = min(mi, a[i]);
                if (a[i] - val < 0) {
                        cout << "NO\n";
                        return;
                }
                a[i] -= min(mi, a[i] - val);
                val = max(val, a[i]);
        }
        for (int i = n - 1; i >= 1; i --) {
                if (a[i] < a[i - 1]) {
                        cout << "NO\n";
                        return;
                }
        }
        cout << "YES\n";
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
