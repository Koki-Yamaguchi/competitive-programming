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
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<int> acc(n), racc(n);
        acc[0] = ~a[0];
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] & ~a[i];
        }
        racc[n - 1] = ~a[n - 1];
        for (int i = n - 2; i >= 0; i --) {
                racc[i] = racc[i + 1] & ~a[i];
        }
        int ma = -1;
        int idx = -1;
        rep(i, n) {
                int val = a[i];
                if (i > 0) val = val & acc[i - 1];
                if (i < n - 1) val = val & racc[i + 1];
                if (val > ma) {
                        ma = val;
                        idx = i;
                }
        }
        vector<int> ans = { a[idx] };
        rep(i, n) {
                if (i != idx) {
                        ans.push_back(a[i]);
                }
        }
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
