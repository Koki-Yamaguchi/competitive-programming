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
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        rep(i, n) {
                cin >> p[i].first >> p[i].second;
        }
        sort(all(p));
        int curx = 0, cury = 0;
        string ans = "";
        rep(i, p.size()) {
                while (curx < p[i].first) {
                        ans.push_back('R');
                        curx ++;
                }
                if (cury > p[i].second) {
                        cout << "NO\n";
                        return;
                }
                while (cury < p[i].second) {
                        cury ++;
                        ans.push_back('U');
                }
        }
        cout << "YES\n";
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
