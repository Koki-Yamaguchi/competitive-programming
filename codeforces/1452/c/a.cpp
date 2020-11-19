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

int slv(const string &s, char left, char right) {
        int n = s.size();
        int cur = 0;
        int ans = 0;
        rep(i, n) {
                if (s[i] == left) {
                        cur ++;
                } else if (s[i] == right) {
                        if (cur > 0) {
                                cur --;
                                ans ++;
                        }
                }
        }
        return ans;
}

void solve() {
        string s;
        cin >> s;
        int ans = 0;
        ans += slv(s, '[', ']');
        ans += slv(s, '(', ')');
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
