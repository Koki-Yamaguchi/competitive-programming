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
        int n, q;
        cin >> n >> q;
        string s; cin >> s;
        vector<bool> zleft(n), zright(n), oleft(n), oright(n);
        zleft[0] = s[0] == '0';
        oleft[0] = s[0] == '1';
        zright[n - 1] = s[n - 1] == '0';
        oright[n - 1] = s[n - 1] == '1';
        rep(i, n) if (i) {
                zleft[i] = zleft[i - 1] || s[i] == '0';
                oleft[i] = oleft[i - 1] || s[i] == '1';
        }
        for (int i = n - 2; i >= 0; i --) {
                zright[i] = zright[i + 1] || s[i] == '0';
                oright[i] = oright[i + 1] || s[i] == '1';
        }
        rep(i, q) {
                int l, r;
                cin >> l >> r;
                l --, r --;
                bool ok = false;
                if (s[l] == '0' && l && zleft[l - 1]) {
                        ok = true;
                }
                if (s[l] == '1' && l && oleft[l - 1]) {
                        ok = true;
                }
                if (s[r] == '0' && r < n - 1 && zright[r + 1]) {
                        ok = true;
                }
                if (s[r] == '1' && r < n - 1 && oright[r + 1]) {
                        ok = true;
                }
                if (ok) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }
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
