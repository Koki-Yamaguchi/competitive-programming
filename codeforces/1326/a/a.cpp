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
        if (n == 1) {
                cout << -1 << '\n';
                return;
        }
        string ans(n - 1, '5');
        for (int i = 2; i <= 9; i ++) {
                ll base = 10;
                ll v = 0;
                rep(j, n - 1) {
                        (v += (base * 5)) %= i;
                        (base *= 10) %= i;
                }
                if (v != 0) {
                        char last = '0' + i;
                        cout << ans << last << '\n';
                        return;
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
