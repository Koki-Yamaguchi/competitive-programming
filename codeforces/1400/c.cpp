#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        string s;
        cin >> s;
        int n = s.size();
        int x;
        cin >> x;
        string res = string(n, '*');
        bool ok = true;
        rep(i, n) {
                if (s[i] == '0') {
                        if (i >= x) {
                                if (res[i - x] == '1') {
                                        ok = false;
                                        break;
                                }
                                res[i - x] = '0';
                        }
                        if (i < n - x) {
                                res[i + x] = '0';
                        }
                } else {
                        if (i >= x && i < n - x) {
                                if (res[i - x] == '0') {
                                        res[i + x] = '1';
                                } else {
                                        res[i - x] = '1';
                                }
                        } else if (i >= x) {
                                if (res[i - x] == '0') {
                                        ok = false;
                                        break;
                                }
                                res[i - x] = '1';
                        } else if (i < n - x) {
                                res[i + x] = '1';
                        } else {
                                ok = false;
                                break;
                        }
                }
        }
        if (!ok) {
                cout << -1 << '\n';
                return;
        }
        rep(i, n) {
                if (res[i] == '*') {
                        res[i] = '1';
                }
        }
        cout << res << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
