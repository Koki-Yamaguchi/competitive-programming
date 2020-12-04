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

int slv(int n, const vector<pair<int, int>> &ps) {
        int ma = -1;
        int mi = 1e9;
        int c = 2005;
        vector<vector<int>> p(c);
        rep(i, ps.size()) {
                ma = max(ma, ps[i].first);
                mi = min(mi, ps[i].first);
                p[ps[i].first].push_back(ps[i].second);
        }
        int res = 0;
        rep(i, c) {
                sort(all(p[i]));
                if (p[i].size() == 0) continue;
                if (p[i].size() == 1) {
                        int l = max(p[i][0], n - p[i][0] - 1);
                        int h = max(i - mi, ma - i);
                        res = max(res, l * h);
                }
                if (p[i].size() >= 2) {
                        int l = max(p[i].front(), n - p[i].front() - 1);
                        int h = max(i - mi, ma - i);
                        res = max(res, l * h);

                        l = max(p[i].back(), n - p[i].back() - 1);
                        h = max(i - mi, ma - i);
                        res = max(res, l * h);

                        int miy = p[i].front();
                        int may = p[i].back();
                        l = may - miy;
                        h = max(i, n - i - 1);
                        res = max(res, l * h);
                }
        }
        return res;
}

void solve() {
        int n; cin >> n;
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        for (int p = 0; p < 10; p ++) {
                vector<pair<int, int>> ps;
                rep(i, n) {
                        rep(j, n) {
                                if (s[i][j] - '0' == p) {
                                        ps.emplace_back(i, j);
                                }
                        }
                }
                int ans0 = slv(n, ps);
                rep(i, ps.size()) {
                        ps[i] = make_pair(ps[i].second, ps[i].first);
                }
                int ans1 = slv(n, ps);
                cout << max(ans0, ans1) << (p == 9 ? '\n' : ' ');
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
