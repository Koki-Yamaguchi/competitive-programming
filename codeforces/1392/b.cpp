#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        long long k;
        cin >> k;
        vector<long long> a(n);
        long long ma = -1e10;
        rep(i, n) {
                cin >> a[i];
                ma = max(ma, a[i]);
        }
        k --;
        rep(i, n) {
                a[i] = ma - a[i];
        }
        if (k & 1) {
                ma = -1e10;
                rep(i, n) {
                        ma = max(ma, a[i]);
                }
                rep(i, n) {
                        cout << ma - a[i] << " \n"[i == n - 1];
                }
        } else {
                rep(i, n) {
                        cout << a[i] << " \n"[i == n - 1];
                }
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
