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
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        vector<vector<bool>> p(n, vector<bool> (n));
        rep(i, n) {
                rep(j, n) {
                        string s0 = s[i];
                        string s1 = s[j];
                        reverse(all(s1));
                        if (s0 == s1) {
                                p[i][j] = true;
                        }
                }
        }
        vector<bool> used(n);
        string fr;
        rep(i, n) {
                rep(j, n) {
                        if (i != j && p[i][j] && not used[i] && not used[j]) {
                                used[i] = true;
                                used[j] = true;
                                fr += s[i];
                        }
                }
        }
        vector<string> ss;
        rep(i, n) {
                if (not used[i] && p[i][i]) {
                        ss.push_back(s[i]);
                }
        }
        string mid;
        if (ss.size() > 0) {
                sort(all(ss), [](const string &a, const string &b) {
                        return a.size() > b.size();
                });
                mid = ss[0];
        }
        string bc = fr;
        reverse(all(bc));
        string ans = fr + mid + bc;
        cout << ans.size() << '\n';
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
