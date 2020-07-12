#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> s(n, vector<char> (n, '0'));
        int sy = 0;
        bool f = false;
        while (true) {
                int y = sy;
                rep(x, n) {
                        if (k == 0) {
                                f = true;
                                break;
                        }
                        s[y][x] = '1';
                        k --;
                        (y += 1) %= n;
                }
                if (f) {
                        break;
                }
                sy ++;
        }
        int ama = 0;
        int ami = 1000;
        rep(i, n) {
                int c = 0;
                rep(j, n) {
                        c += s[i][j] == '1';
                }
                ami = min(ami, c);
                ama = max(ama, c);
        }
        int bma = 0;
        int bmi = 1000;
        rep(i, n) {
                int c = 0;
                rep(j, n) {
                        c += s[j][i] == '1';
                }
                bmi = min(bmi, c);
                bma = max(bma, c);
        }
        int ans = (ama - ami) * (ama - ami) + (bma - bmi) * (bma - bmi);
        cout << ans << '\n';
        rep(i, n) {
                rep(j, n) {
                        cout << s[i][j];
                }
                cout << '\n';
        }
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
