#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        bool ex = false;
        rep(i, n) {
                cin >> a[i];
        }
        if (n == 1) {
                if (a[0] == k) {
                        cout << "yes\n";
                } else {
                        cout << "no\n";
                }
                return;
        }
        rep(i, n) {
                if (a[i] == k) {
                        ex = true;
                }
                if (a[i] >= k) a[i] = 1;
                else a[i] = 0;
        }
        rep(i, n) {
                int c = 0;
                for (int j = i; j <= min(n - 1, i + 2); j ++) {
                        c += a[j];
                }
                if (c >= 2 && ex) {
                        cout << "yes\n";
                        return;
                }
        }
        cout << "no\n";
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
