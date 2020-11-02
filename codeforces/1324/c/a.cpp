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

template<class Iterator> auto consecutive_element_count(Iterator first, Iterator last) {
        vector<pair<decltype(*first), int>> cnt;
        auto it = first;
        while (it != last) {
                if (cnt.empty() || cnt.back().first != *it) {
                        cnt.emplace_back(*it, 1);
                } else {
                        cnt.back().second ++;
                }
                it ++;
        }
        return cnt;
}

void solve() {
        string s; cin >> s;
        auto c = consecutive_element_count(all(s));
        int ma = 1;
        rep(i, c.size()) {
                if (c[i].first == 'L') {
                        ma = max(ma, c[i].second + 1);
                }
        }
        cout << ma << '\n';
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
