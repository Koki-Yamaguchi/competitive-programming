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
        string s, t; cin >> s >> t;
        int sn = s.size();
        int tn = t.size();
        vector<vector<int>> nxt(sn, vector<int> (26, -1));
        for (int i = sn - 1; i >= 0; i --) {
                if (i < sn - 1) {
                        rep(j, 26) {
                                nxt[i][j] = nxt[i + 1][j];
                        }
                }
                nxt[i][s[i] - 'a'] = i;
        }
        int ans = 1;
        int sp = 0, tp = 0;
        while (true) {
                int v = t[tp] - 'a';
                int pos = nxt[sp][v];
                if (sp == 0 && pos == -1) {
                        cout << "-1\n";
                        return;
                }
                if (pos != -1) {
                        sp = pos + 1;
                        tp ++;
                }
                if (tp == tn) {
                        break;
                }
                if (pos == -1 || sp >= sn) {
                        sp = 0;
                        ans ++;
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
