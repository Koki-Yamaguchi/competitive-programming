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
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        set<int> st;
        rep(i, n) {
                if (a[i] == -1) {
                        if (i && a[i - 1] != -1) {
                                st.insert(a[i - 1]);
                        }
                        if (i < n - 1 && a[i + 1] != -1) {
                                st.insert(a[i + 1]);
                        }
                }
        }
        int ma = -1, mi = 1e9 + 10;
        for (auto it : st) {
                ma = max(ma, it);
                mi = min(mi, it);
        }
        int k = (mi + ma) /2;
        rep(i, n) {
                if (a[i] == -1) {
                        a[i] = k;
                }
        }
        int ans = 0;
        rep(i, n - 1) {
                ans = max(ans, abs(a[i] - a[i + 1]));
        }
        cout << ans << " " << k << '\n';
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
