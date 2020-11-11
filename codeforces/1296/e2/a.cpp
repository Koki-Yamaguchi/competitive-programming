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
        vector<int> a(n);
        rep(i, n) {
                a[i] = s[i] - 'a';
        }
        vector<int> v;
        vector<int> ans(n);
        rep(i, n) {
                int idx = lower_bound(v.begin(), v.end(), - a[i]) - v.begin();
                if (idx == v.size()) {
                        v.emplace_back(- a[i]);
                        ans[i] = v.size();
                } else {
                        v[idx] = - a[i];
                        ans[i] = idx + 1;
                }
        }
        cout << v.size() << '\n';
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
