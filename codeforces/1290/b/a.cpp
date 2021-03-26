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
        string s; cin >> s;
        int n = s.size();
        vector<vector<int>> cnt(n + 1, vector<int> (26));
        rep(i, 26) {
                rep(j, n) {
                        cnt[j + 1][i] = cnt[j][i] + (s[j] - 'a' == i);
                }
        }
        int q;
        cin >> q;
        vector<int> l(q), r(q);
        rep(i, q) {
                cin >> l[i] >> r[i];
                l[i] --;
        }
        rep(p, q) {
                int len = r[p] - l[p];
                if (len == 1) {
                        cout << "Yes\n";
                        continue;
                }
                bool f = false;
                rep(i, 26) {
                        int c = cnt[r[p]][i] - cnt[l[p]][i];
                        if (len == c) {
                                f = true;
                                break;
                        }
                }
                if (f) {
                        cout << "No\n";
                } else {
                        cout << "Yes\n";
                }
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        //int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
