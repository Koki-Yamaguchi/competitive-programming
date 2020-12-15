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

void chmin(int &a, int b) {
        a = min(a, b);
}

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        int oc = 0, ec = 0;
        set<int> used;
        rep(i, n) {
                cin >> a[i];
                a[i] --;
                used.insert(a[i]);
        }
        rep(i, n) {
                if (used.count(i) == 0) {
                        if (i & 1) {
                                oc ++;
                        } else {
                                ec ++;
                        }
                }
        }
        const int inf = 1e9;
        vector<vector<vector<int>>> cur(2, vector<vector<int>> (oc + 1, vector<int> (ec + 1, inf)));
        cur[0][oc][ec] = 0;
        cur[1][oc][ec] = 0;
        rep(i, n) {
                vector<vector<vector<int>>> nxt(2, vector<vector<int>> (oc + 1, vector<int> (ec + 1, inf)));
                if (a[i] == -1) {
                        rep(x, oc + 1) {
                                rep(y, ec + 1) {
                                        if (x) chmin(nxt[1][x - 1][y], cur[0][x][y] + 1);
                                        if (x) chmin(nxt[1][x - 1][y], cur[1][x][y]);
                                        if (y) chmin(nxt[0][x][y - 1], cur[0][x][y]);
                                        if (y) chmin(nxt[0][x][y - 1], cur[1][x][y] + 1);
                                }
                        }
                } else {
                        rep(x, oc + 1) {
                                rep(y, ec + 1) {
                                        if (a[i] & 1) {
                                                chmin(nxt[1][x][y], cur[0][x][y] + 1);
                                                chmin(nxt[1][x][y], cur[1][x][y]);
                                        } else {
                                                chmin(nxt[0][x][y], cur[0][x][y]);
                                                chmin(nxt[0][x][y], cur[1][x][y] + 1);
                                        }
                                }
                        }
                }
                swap(cur, nxt);
        }
        cout << min(cur[0][0][0], cur[1][0][0]) << '\n';
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
