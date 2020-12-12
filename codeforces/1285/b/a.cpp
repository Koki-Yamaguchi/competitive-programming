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
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        ll acc = 0;
        bool ng = false;
        rep(i, n) {
                acc += a[i];
                if (acc <= 0) {
                        ng = true;
                }
        }
        acc = 0;
        for (int i = n - 1; i >= 0; i --) {
                acc += a[i];
                if (acc <= 0) {
                        ng = true;
                }
        }
        cout << (ng ? "NO\n" : "YES\n");
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
