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
        int n; cin >> n;
        string s; cin >> s;
        int c = 0;
        int d = 0;
        rep(i, n) {
                c += (s[i] == '(');
                d += (s[i] == ')');
        }
        if (c != d) {
                cout << -1 << '\n';
                return;
        }
        int cur = 0;
        int ans = 0;
        int need = 0;
        rep(i, n) {
                if (s[i] == '(') {
                        if (cur < 0) {
                                ans ++;
                                need --;
                        }
                        cur ++;
                } else {
                        if (cur <= 0) {
                                ans ++;
                                need ++;
                        }
                        cur --;
                }
        }
        cout << ans << '\n';
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
