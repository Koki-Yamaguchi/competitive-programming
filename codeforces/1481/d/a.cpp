#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> ga(n, vector<bool> (n));
        vector<vector<bool>> gb(n, vector<bool> (n));
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        rep(i, n) {
                rep(j, n) {
                        if (i != j) {
                                if (s[i][j] == 'a') {
                                        ga[i][j] = true;
                                } else {
                                        gb[i][j] = true;
                                }
                        }
                }
        }
        vector<int> ans;
        rep(i, n) {
                rep(j, n) {
                        if ((ga[i][j] && ga[j][i]) || (gb[i][j] && gb[j][i])) {
                                bool f = false;
                                m ++;
                                while (m --) {
                                        ans.push_back(f ? (i + 1) : (j + 1));
                                        f = not f;
                                }
                                goto end;
                        }
                }
        }
        end:;
        if (ans.size() == 0 && n >= 3) {
                if (m & 1) {
                        bool f = false;
                        m ++;
                        while (m --) {
                                ans.push_back(f ? 1 : 2);
                                f = not f;
                        }
                } else {
                        bool f = false;
                        rep(i, n) {
                                bool in = false, out = false;
                                int inidx = -1, outidx = -1;
                                rep(j, n) {
                                        if (ga[i][j]) {
                                                out = true;
                                                outidx = j;
                                                break;
                                        }
                                }
                                rep(j, n) {
                                        if (ga[j][i]) {
                                                in = true;
                                                inidx = j;
                                                break;
                                        }
                                }
                                dump(outidx);
                                dump(inidx);
                                if (in && out) {
                                        int mmm = m / 2;
                                        if (mmm % 2 == 0) {
                                                ans.push_back(i + 1);
                                                bool r = true;
                                                while (mmm --) {
                                                        ans.push_back(r ? outidx + 1 : i + 1);
                                                        r = not r;
                                                }
                                                mmm = m / 2;
                                                r = true;
                                                while (mmm --) {
                                                        ans.push_back(r ? inidx + 1 : i + 1);
                                                        r = not r;
                                                }
                                        } else {
                                                ans.push_back(inidx + 1);
                                                bool r = false;
                                                while (mmm --) {
                                                        ans.push_back(r ? inidx + 1 : i + 1);
                                                        r = not r;
                                                }
                                                mmm = m / 2;
                                                r = true;
                                                while (mmm --) {
                                                        ans.push_back(r ? outidx + 1 : i + 1);
                                                        r = not r;
                                                }
                                        }
                                        f = true;
                                        break;
                                }
                        }
                        assert(f);
                }
        }
        if (ans.size() == 0 && n == 2) {
                if (m & 1) {
                        bool f = false;
                        m ++;
                        while (m --) {
                                ans.push_back(f ? 1 : 2);
                                f = not f;
                        }
                }
        }
        if (ans.size()) {
                cout << "YES\n";
                cout << ans << '\n';
        } else {
                cout << "NO\n";
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
