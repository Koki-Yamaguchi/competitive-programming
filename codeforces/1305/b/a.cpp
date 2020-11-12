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
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n - 1;
        vector<int> ans;
        while (l <= r) {
                while (s[l] == ')') {
                        l ++;
                }
                while (s[r] == '(') {
                        r --;
                }
                if (l < r) {
                        ans.push_back(l + 1);
                        ans.push_back(r + 1);
                }
                l ++;
                r --;
        }
        sort(all(ans));
        if (ans.size() == 0) {
                cout << 0 << '\n';
        } else {
                cout << 1 << '\n';
                cout << ans.size() << '\n';
                cout << ans << '\n';
        }
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
