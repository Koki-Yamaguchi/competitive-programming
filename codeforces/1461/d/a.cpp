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
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        vector<ll> s(q);
        rep(i, q) {
                cin >> s[i];
        }
        vector<ll> acc(n); acc[0] = a[0];
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] + a[i];
        }
        set<ll> vals;
        function<void (int, int)> dfs = [&](int l, int r) {
                ll sum = acc[r] - (l ? acc[l - 1] : 0);
                vals.insert(sum);
                if (r == l) {
                        return;
                }
                ll v = (a[l] + a[r]) / 2;
                int idx = upper_bound(all(a), v) - a.begin();
                if (idx == r + 1) {
                        return;
                }
                assert(idx > 0);
                idx --;
                dfs(l, idx);
                dfs(idx + 1, r);
        };
        dfs(0, n - 1);
        rep(i, q) {
                if (vals.count(s[i])) {
                        cout << "Yes\n";
                } else {
                        cout << "No\n";
                }
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
