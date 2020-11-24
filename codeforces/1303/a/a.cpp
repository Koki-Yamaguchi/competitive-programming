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
        string s; cin >> s;
        int n = s.size();
        int bg = -1, ed = -1;
        rep(i, n) {
                if (s[i] == '1') {
                        bg = i;
                        break;
                }
        }
        for (int i = n - 1; i >= 0; i --) {
                if (s[i] == '1') {
                        ed = i;
                        break;
                }
        }
        int c = 0;
        for (int i = bg; i < ed; i ++) {
                c += s[i] == '0';
        }
        cout << c << '\n';
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
