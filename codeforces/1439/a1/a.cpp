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
        vector<vector<int>> ans;
        vector<vector<int>> s(h, vector<int> (w));
        rep(i, h) {
                string t;
                cin >> t;
                rep(j, w) {
                        s[i][j] = t[j] - '0';
                }
        }
        auto exc = [&](int y0, int x0, int y1, int x1, int y2, int x2) {
                s[y0][x0] = s[y0][x0] ^ 1;
                s[y1][x1] = s[y1][x1] ^ 1;
                s[y2][x2] = s[y2][x2] ^ 1;
                vector<int> r = {y0 + 1, x0 + 1, y1 + 1, x1 + 1, y2 + 1, x2 + 1};
                ans.push_back(r);
        };
        if ((h & 1) && (w & 1)) {
                if (s[h - 1][w - 1] == 1) {
                        exc(h - 1, w - 1, h - 2, w - 1, h - 1, w - 2);
                }
                for (int i = 0; i < h - 1; i += 2) {
                        if (s[i][w - 1] == 1) {
                                if (s[i + 1][w - 1] == 1) {
                                        exc(i, w - 1, i + 1, w - 1, i, w - 2);
                                } else {
                                        exc(i, w - 1, i, w - 2, i + 1, w - 2);
                                }
                        } else {
                                if (s[i + 1][w - 1] == 1) {
                                        exc(i + 1, w - 1, i, w - 2, i + 1, w - 2);
                                }
                        }
                }
                for (int i = 0; i < w - 1; i += 2) {
                        if (s[h - 1][i] == 1) {
                                if (s[h - 1][i + 1] == 1) {
                                        exc(h - 1, i, h - 1, i + 1, h - 2, i);
                                } else {
                                        exc(h - 1, i, h - 2, i, h - 2, i + 1);
                                }
                        } else {
                                if (s[h - 1][i + 1] == 1) {
                                        exc(h - 1, i + 1, h - 2, i, h - 2, i + 1);
                                }
                        }
                }
        } else if (h & 1) {
                for (int i = 0; i < w - 1; i += 2) {
                        if (s[h - 1][i] == 1) {
                                if (s[h - 1][i + 1] == 1) {
                                        exc(h - 1, i, h - 1, i + 1, h - 2, i);
                                } else {
                                        exc(h - 1, i, h - 2, i, h - 2, i + 1);
                                }
                        } else {
                                if (s[h - 1][i + 1] == 1) {
                                        exc(h - 1, i + 1, h - 2, i, h - 2, i + 1);
                                }
                        }
                }
        } else if (w & 1) {
                for (int i = 0; i < h - 1; i += 2) {
                        if (s[i][w - 1] == 1) {
                                if (s[i + 1][w - 1] == 1) {
                                        exc(i, w - 1, i + 1, w - 1, i, w - 2);
                                } else {
                                        exc(i, w - 1, i, w - 2, i + 1, w - 2);
                                }
                        } else {
                                if (s[i + 1][w - 1] == 1) {
                                        exc(i + 1, w - 1, i, w - 2, i + 1, w - 2);
                                }
                        }
                }
        }
        if (h & 1) h --;
        if (w & 1) w --;
        for (int i = 0; i < h; i += 2) {
                for (int j = 0; j < w; j += 2) {
                        while (true) {
                                int c = 0;
                                for (int ii = i; ii < i + 2; ii ++) {
                                        for (int jj = j; jj < j + 2; jj ++) {
                                                c += (s[ii][jj] == 1);
                                        }
                                }
                                if (c == 0) {
                                        break;
                                } else if (c == 1 || c == 3) {
                                        vector<int> p;
                                        int iii = -1, jjj = -1;
                                        for (int ii = i; ii < i + 2; ii ++) {
                                                for (int jj = j; jj < j + 2; jj ++) {
                                                        if (s[ii][jj] == 0) {
                                                                iii = ii;
                                                                jjj = jj;
                                                                goto end;
                                                        }
                                                }
                                        }
                                        end:;
                                        for (int ii = i; ii < i + 2; ii ++) {
                                                for (int jj = j; jj < j + 2; jj ++) {
                                                        if (ii != iii || jj != jjj) {
                                                                p.push_back(ii);
                                                                p.push_back(jj);
                                                        }
                                                }
                                        }
                                        assert(p.size() == 6);
                                        exc(p[0], p[1], p[2], p[3], p[4], p[5]);
                                } else if (c == 2 || c == 4) {
                                        vector<int> p;
                                        int iii = -1, jjj = -1;
                                        for (int ii = i; ii < i + 2; ii ++) {
                                                for (int jj = j; jj < j + 2; jj ++) {
                                                        if (s[ii][jj] == 1) {
                                                                iii = ii;
                                                                jjj = jj;
                                                                goto end2;
                                                        }
                                                }
                                        }
                                        end2:;
                                        for (int ii = i; ii < i + 2; ii ++) {
                                                for (int jj = j; jj < j + 2; jj ++) {
                                                        if (ii != iii || jj != jjj) {
                                                                p.push_back(ii);
                                                                p.push_back(jj);
                                                        }
                                                }
                                        }
                                        assert(p.size() == 6);
                                        exc(p[0], p[1], p[2], p[3], p[4], p[5]);
                                }
                        }
                }
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i] << '\n';
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
