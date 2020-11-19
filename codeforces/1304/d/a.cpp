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

vector<int> calc(const string &s) {
        int n = s.size();
        int cur = n + 1;
        vector<int> res;
        string t = '>' + s;
        int i = 0;
        while (i < t.size()) {
                assert(t[i] == '>');
                int j = i + 1;
                while (j < t.size() && t[j] == '<') {
                        j ++;
                }
                int d = j - i;
                int val = cur - d + 1;
                while (val <= cur) {
                        res.push_back(val);
                        val ++;
                }
                cur = cur - d;
                i = j;
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> ans_mi = calc(s);
        reverse(all(s));
        rep(i, n - 1) {
                s[i] ^= '<' ^ '>';
        }
        vector<int> ans_ma = calc(s);
        reverse(all(ans_ma));
        cout << ans_mi << '\n' << ans_ma << '\n';
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
