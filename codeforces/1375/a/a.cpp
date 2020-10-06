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
        rep(i, n) {
                if (i & 1) {
                        if (a[i] < 0) {
                                a[i] *= -1;
                        }
                } else {
                        if (a[i] > 0) {
                                a[i] *= -1;
                        }
                }
        }
        rep(i, n) {
                cout << a[i] << " \n"[i == n - 1];
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
