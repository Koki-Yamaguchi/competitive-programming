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

template<typename T>
int longest_increasing_subsequence(const vector<T> &v, bool strict) {
        vector<T> lis;
        for (const T &e : v) {
                int idx;
                if (strict) {
                        idx = lower_bound(lis.begin(), lis.end(), e) - lis.begin();
                } else {
                        idx = upper_bound(lis.begin(), lis.end(), e) - lis.begin();
                }
                if (idx == lis.size()) {
                        lis.emplace_back(e);
                } else {
                        lis[idx] = e;
                }
        }
        return (int) lis.size();
}

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k);
        rep(i, n) {
                cin >> a[i];
                a[i] -= i;
        }
        vector<bool> fixed(n);
        rep(i, k) {
                cin >> b[i];
                b[i] --;
                fixed[b[i]] = true;
        }
        rep(i, k - 1) {
                if (a[b[i + 1]] < a[b[i]]) {
                        cout << -1 << '\n';
                        return;
                }
        }

        a.push_back(1e9 + 10);
        fixed.push_back(true);

        reverse(all(a));
        reverse(all(fixed));

        a.push_back(-1e9 - 10);
        fixed.push_back(true);

        reverse(all(a));
        reverse(all(fixed));

        n += 2;

        vector<int> cur;
        int li = -1, l = -1;
        int ans = 0;
        rep(i, n) {
                if (not fixed[i]) {
                        cur.push_back(a[i]);
                } else {
                        int r = a[i];
                        vector<int> good;
                        for (auto it : cur) {
                                if (l <= it && it <= r) {
                                        good.push_back(it);
                                }
                        }
                        int lis = longest_increasing_subsequence(good, false);
                        assert(i - li - 1 >= lis);
                        ans += (i - li - 1) - lis;
                        li = i;
                        l = a[i];
                        cur.clear();
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
