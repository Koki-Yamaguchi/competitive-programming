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

pair<int, int> f(int n, int m, const vector<vector<int>> &a, int x) {
        vector<int> b(n);
        rep(i, n) {
                rep(j, m) {
                        if (a[i][j] >= x) {
                                b[i] |= 1 << j;
                        }
                }
        }
        set<int> st;
        map<int, int> idx;
        rep(i, n) {
                st.insert(b[i]);
                idx[b[i]] = i;
        }
        vector<int> c;
        for (auto v : st) {
                c.push_back(v);
        }
        rep(i, c.size()) {
                rep(j, c.size()) {
                        int d = c[i] | c[j];
                        if (d == ((1 << m) - 1)) {
                                return {idx[c[i]], idx[c[j]]};
                        }
                }
        }
        return {-1, -1};
}

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        rep(i, n) {
                rep(j, m) {
                        cin >> a[i][j];
                }
        }
        int lb = 0, ub = 1e9 + 10;
        while (ub - lb > 1) {
                int x = (lb + ub) / 2;
                pair<int, int> res = f(n, m, a, x);
                if (res.first != -1) {
                        lb = x;
                } else {
                        ub = x;
                }
        }
        auto [ansi, ansj] = f(n, m, a, lb);
        assert(ansi != -1);
        cout << ansi + 1 << " " << ansj + 1 << '\n';
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
