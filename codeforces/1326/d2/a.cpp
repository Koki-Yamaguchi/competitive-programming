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

// ref: https://snuke.hatenablog.com/entry/2014/12/02/235837
// verified at http://codeforces.com/contest/1326/problem/D2
// abaaababa -> 121412321
vector<int> manacher(const string &s) {
        int n = s.size();
        vector<int> res(n);
        int i = 0, j = 0;
        while (i < s.size()) {
                while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
                        j ++;
                }
                res[i] = j;
                int k = 1;
                while (i - k >= 0 && k + res[i - k] < j) {
                        res[i + k] = res[i - k];
                        k ++;
                }
                i += k;
                j -= k;
        }
        return res;
}

vector<int> manacher_even(const string &s) {
        string t;
        int n = s.size();
        rep(i, n) {
                t.push_back(s[i]);
                if (i != n - 1) {
                        t.push_back('$');
                }
        }
        vector<int> res;
        auto mnch = manacher(t);
        rep(i, mnch.size()) {
                if (i & 1) {
                        res.push_back(mnch[i] / 2);
                }
        }
        return res;
}

void solve() {
        string s; cin >> s;
        int n = s.size();
        auto odd = manacher(s);
        assert(odd.size() == n);
        auto even = manacher_even(s);
        assert(even.size() == n - 1);
        int lma = 0;
        rep(i, n / 2) {
                if (s[i] != s[n - 1 - i]) {
                        break;
                }
                lma ++;
        }
        int lenma = 0;
        pair<int, int> seg = {-1, -1};
        rep(i, n) {
                rep(j, 2) {
                        int l, r;
                        if (j == 0) {
                                l = i - odd[i] + 1;
                                r = i + odd[i] - 1;
                        } else {
                                if (i == n - 1) {
                                        break;
                                }
                                l = i - even[i] + 1;
                                r = i + even[i];
                        }
                        if (l <= lma || r >= n - 1 - lma) {
                                int side = min(l, n - 1 - r);
                                int len = side * 2 + r - l + 1;
                                if (len > lenma) {
                                        lenma = len;
                                        seg = {l, r};
                                }
                        }
                }
        }
        auto [l, r] = seg;
        int side = min(l, n - 1 - r);
        string ans;
        rep(i, side) {
                ans.push_back(s[i]);
        }
        for (int i = l; i <= r; i ++) {
                ans.push_back(s[i]);
        }
        for (int i = n - side; i < n; i ++) {
                ans.push_back(s[i]);
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
