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
        vector<int> a(n), c(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        rep(i, n) {
                cin >> c[i];
                c[i] --;
        }
        vector<int> to(n);
        rep(i, n) {
                to[a[i]] = i;
        }
        int ans = n + 10;
        map<int, int> vis;
        rep(i, n) {
                if (vis.count(i) == 0) {
                        map<int, int> prev;
                        int p = 0;
                        int cur = i;
                        while (true) {
                                vis[cur] ++;
                                if (vis[cur] == 3) {
                                        break;
                                }
                                if (prev.count(c[cur])) {
                                        ans = min(ans, p - prev[c[cur]]);
                                }
                                prev[c[cur]] = p ++;
                                cur = to[cur];
                        }
                }
        }
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
