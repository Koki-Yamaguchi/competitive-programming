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
        int h, w;
        cin >> h >> w;
        vector<string> tmp(h);
        rep(i, h) {
                cin >> tmp[i];
        }
        if (h >= 4 && w >= 4) {
                cout << "-1\n";
                return;
        }
        vector<vector<int>> s;
        if (h <= 3) {
                s.resize(w);
                rep(i, w) {
                        rep(j, h) {
                                s[i].push_back(tmp[j][i] - '0');
                        }
                }
                swap(h, w);
        } else {
                s.resize(h);
                rep(i, h) {
                        rep(j, w) {
                                s[i].push_back(tmp[i][j] - '0');
                        }
                }
        }
        vector<int> cur(1 << w);
        rep(i, h) {
                vector<int> nxt(1 << w, 1e9);
                rep(q, 1 << w) {
                        int add = 0;
                        rep(j, w) {
                                add += s[i][j] != ((q >> j) & 1);
                        }
                        if (i) {
                                rep(p, 1 << w) {
                                        bool ok = true;
                                        rep(x, w - 1) {
                                                int cnt = 0;
                                                cnt += (p >>  x)      & 1;
                                                cnt += (p >> (x + 1)) & 1;
                                                cnt += (q >>  x)      & 1;
                                                cnt += (q >> (x + 1)) & 1;
                                                if (cnt % 2 == 0) {
                                                        ok = false;
                                                        break;
                                                }
                                        }
                                        if (ok) {
                                                nxt[q] = min(nxt[q], cur[p] + add);
                                        }
                                }
                        } else {
                                nxt[q] = add;
                        }
                }
                swap(nxt, cur);
        }
        cout << *min_element(all(cur)) << '\n';
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
