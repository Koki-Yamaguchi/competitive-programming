#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        bool dec = false;
        for (int i = n - 2; i >= 0; i --) {
                if (a[i + 1] > a[i]) {
                        dec = true;
                } else if (a[i + 1] < a[i] && dec) {
                        cout << (i + 1) << '\n';
                        return;
                }
        }
        cout << 0 << '\n';
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
