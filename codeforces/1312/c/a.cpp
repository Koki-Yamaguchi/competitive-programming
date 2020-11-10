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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        set<int> used;
        ll b = 1;
        while (b < 1e16) {
                b *= k;
        }
        rep(i, n) {
                ll c = b;
                int cnt = 0;
                while (c) {
                        if (a[i] >= c) {
                                if (used.count(cnt)) {
                                        cout << "NO\n";
                                        return;
                                }
                                used.insert(cnt);
                                a[i] -= c;
                        }
                        c /= k;
                        cnt ++;
                }
                if (a[i] != 0) {
                        cout << "NO\n";
                        return;
                }
        }
        cout << "YES\n";
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
