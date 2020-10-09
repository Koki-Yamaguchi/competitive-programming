#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        if (n < k) {
                cout << "NO\n";
                return;
        }
        if (k % 2 == 0) {
                if (n & 1) {
                        cout << "NO\n";
                        return;
                } else {
                        cout << "YES\n";
                        rep(i, k - 1) {
                                cout << 1 << " ";
                        }
                        cout << n - (k - 1) << '\n';
                }
        } else {
                if (n & 1) {
                        cout << "YES\n";
                        rep(i, k - 1) {
                                cout << 1 << " ";
                        }
                        cout << n - (k - 1) << '\n';
                } else {
                        if (n < 2 * k) {
                                cout << "NO\n";
                                return;
                        } else {
                                cout << "YES\n";
                                rep(i, k - 1) {
                                        cout << 2 << " ";
                                }
                                cout << n - 2 * (k - 1) << '\n';
                        }
                }
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
