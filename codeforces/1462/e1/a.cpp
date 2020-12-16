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
        int n, m, k;
        cin >> n; m = 3, k = 2;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        vector<pair<int, int>> cnt;
        rep(i, n) {
                if (cnt.empty() || cnt.back().first != a[i]) {
                        cnt.emplace_back(a[i], 1);
                } else {
                        cnt.back().second ++;
                }
        }
        int sz = cnt.size();
        vector<int> acc(sz); acc[0] = cnt[0].second;
        rep(i, sz) if (i) {
                acc[i] = acc[i - 1] + cnt[i].second;
        }
        ll ans = 0;
        auto C = [&](int n, int r) {
                ll res = 1;
                int c = r;
                while (c --) {
                        res *= n;
                        n --;
                }
                while (r) {
                        res /= r;
                        r --;
                }
                return res;
        };
        rep(i, sz) {
                int v = cnt[i].first;
                int c = cnt[i].second;
                pair<int, int> r = {v + k, 1e9};
                int pos = upper_bound(all(cnt), r) - cnt.begin();
                pos --;
                int free = acc[pos] - acc[i];
                for (int take = 1; take <= min(c, m); take ++) {
                        ans += C(c, take) * C(free, m - take);
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
