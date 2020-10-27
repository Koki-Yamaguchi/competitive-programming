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
        int h, w, k;
        cin >> h >> w >> k;
        rep(i, 2 * k) {
                int a, b;
                cin >> a >> b;
        }
        cout << (h - 1 + w - 1 + h * w) << '\n';
        rep(i, h - 1) cout << "U";
        rep(i, w - 1) cout << "L";
        rep(i, h) {
                string mv = string(w - 1, "LR"[i % 2 == 0]) + "D";
                cout << mv;
        }
        cout << '\n';
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
