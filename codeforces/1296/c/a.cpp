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
        string s;
        cin >> s;
        map<pair<int, int>, int> prev;
        int y = 0, x = 0;
        prev[make_pair(y, x)] = 0;
        int ans = 1e9;
        int l = -1, r = -1;
        rep(i, n) {
                if (s[i] == 'L') {
                        x --;
                }
                if (s[i] == 'R') {
                        x ++;
                }
                if (s[i] == 'D') {
                        y --;
                }
                if (s[i] == 'U') {
                        y ++;
                }
                if (prev.count(make_pair(y, x))) {
                        if (i - prev[make_pair(y, x)] < ans) {
                                ans = i - prev[make_pair(y, x)];
                                l = prev[make_pair(y, x)];
                                r = i;
                        }
                }
                prev[make_pair(y, x)] = i + 1;
        }
        if (l == -1) {
                cout << -1 << '\n';
        } else {
                cout << l + 1 << " " << r + 1 << '\n';
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
