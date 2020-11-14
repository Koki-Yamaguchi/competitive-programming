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
        int n; cin >> n;
        string s; cin >> s;
        vector<pair<string, int>> ss;
        for (int k = 0; k < n; k ++) {
                bool rev = ((n - k) % 2 == 0);
                string t = s.substr(k, n - k);
                string l = s.substr(0, k);
                if (!rev) reverse(all(l));
                ss.emplace_back(t + l, k);
        }
        sort(all(ss));
        cout << ss[0].first << '\n';
        cout << ss[0].second + 1 << '\n';
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
