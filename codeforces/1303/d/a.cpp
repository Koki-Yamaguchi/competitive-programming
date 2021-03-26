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
        ll n;
        int m;
        cin >> n >> m;
        vector<ll> a(m);
        rep(i, m) {
                cin >> a[i];
        }
        ll sum = accumulate(all(a), 0ll);
        if (sum < n) {
                cout << "-1\n";
                return;
        }
        sort(all(a));
        map<int, int> cnt;
        rep(i, n) {
                int tz = __builtin_ctzll(a[i]);
                cnt[tz] ++;
        }
        int bm = 62;
        vector<int> ok(bm, true), divs(bm, false);
        rep(i, bm) {
                if ((n >> i) & 1) {
                        ok[i] = false;
                }
        }
        rep(i, bm) {
                if (cnt[i] && ((n >> i) & 1)) {
                        cnt[i] --;
                        ok[i] = true;
                }
                cnt[i + 1] += cnt[i] / 2;
        }
        bool f = true;
        rep(i, bm) {
                if (not ok[i]) {
                        f = false;
                }
        }
        if (f) {
                cout << "0\n";
                return;
        }
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
