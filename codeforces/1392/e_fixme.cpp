#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<vector<long long>> s(50, vector<long long> (50, -1));
        int y = 0, x = 0;
        int nxt = 1;

        long long base = 2;
        long long cur = 1;
        long long diff = 1;
        while (true) {
                if (x == 50) break;
                s[y][x] = cur;
                cur += max(1ll, diff / 2);
                if (x == 0) {
                        x = nxt;
                        y = 0;
                        nxt ++;
                        cur = base;
                        base *= 2;
                        diff *= 2;
                } else {
                        x --;
                        y ++;
                }
        }
        rep(i, n) {
                rep(j, n) {
                        cout << s[i][j];
                        if (j == n - 1) {
                                cout << endl;
                        } else {
                                cout << " ";
                        }
                }
        }
        vector<vector<long long>> ma(n, vector<long long> (n, 0));
        ma[0][0] = 1;
        rep(i, n) {
                rep(j, n) {
                        if (i && j) {
                                ma[i][j] = max(ma[i - 1][j], ma[i][j - 1] + s[i][j]);
                        } else if (i) {
                                ma[i][j] = ma[i - 1][j] + s[i][j];
                        } else if (j) {
                                ma[i][j] = ma[i][j - 1] + s[i][j];
                        }
                }
        }
        /*
        cerr << "ma" << endl;
        rep(i, n) {
                rep(j, n) cerr << ma[i][j] << " \n"[j == n - 1];
        }
        */
        int q;
        cin >> q;
        cout.flush();
        while (q --) {
                long long sum;
                cin >> sum;
                y = n - 1;
                x = n - 1;
                vector<pair<long long, long long>> ans;
                sum -= s[n - 1][n - 1];
                ans.emplace_back(y, x);
                while (x != 0 || y != 0) {
                        if (x == 0) {
                                y --;
                        } else if (y == 0) {
                                x --;
                        } else {
                                long long m = ma[y - 1][x];
                                /*
                                cerr << "sum = " << sum << endl;
                                cerr << "m = " << m << endl;
                                */
                                if (sum <= m) {
                                        // cerr << "move y" << endl;
                                        y --;
                                } else {
                                        // cerr << "move x" << endl;
                                        x --;
                                }
                                sum -= s[y][x];
                        }
                        ans.emplace_back(y, x);
                }
                reverse(ans.begin(), ans.end());
                rep(i, ans.size()) {
                        cout << ans[i].first << " " << ans[i].second << endl;
                }
        cout.flush();
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
