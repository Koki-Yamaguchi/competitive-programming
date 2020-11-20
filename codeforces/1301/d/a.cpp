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
        int h, w, k;
        cin >> h >> w >> k;
        if (4 * h * w - 2 * h - 2 * w < k) {
                cout << "NO\n";
                return;
        }
        cout << "YES\n";
        if (w == 1) {
                cout << k << '\n';
                rep(i, h - 1) {
                        if (k) {
                                k --;
                                cout << "1 D\n";
                        }
                }
                rep(i, h - 1) {
                        if (k) {
                                k --;
                                cout << "1 U\n";
                        }
                }
                return;
        }
        vector<pair<int, string>> res, ans;
        res.emplace_back(w - 1, "R");
        res.emplace_back(w - 1, "L");
        res.emplace_back(1, "D");
        rep(i, h - 1) {
                res.emplace_back(w - 1, "RUD");
                res.emplace_back(w - 1, "L");
                if (i != h - 2) {
                        res.emplace_back(1, "D");
                }
        }
        res.emplace_back(h - 1, "U");

        rep(i, res.size()) {
                int f = res[i].first;
                int len = res[i].second.size();
                string str = res[i].second;
                if (f * len <= k) {
                        ans.push_back(res[i]);
                        k -= f * len;
                        if (k == 0) break;
                } else {
                        int c = 0;
                        while (k >= len) {
                                c ++;
                                k -= len;
                        }
                        if (c >= 1) {
                                ans.emplace_back(c, str);
                        }
                        assert(k <= len);
                        if (k == 0) {
                                break;
                        }
                        ans.emplace_back(1, str.substr(0, k));
                        break;
                }
        }
        assert(ans.size() <= 3000);
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i].first << " " << ans[i].second << '\n';
        }
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
