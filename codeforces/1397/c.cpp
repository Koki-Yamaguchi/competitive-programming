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
        if (n == 1) {
                cout << 1 << " " << 1 << '\n';
                cout << -a[0] << '\n';
                cout << 1 << " " << 1 << '\n';
                cout << 0 << '\n';
                cout << 1 << " " << 1 << '\n';
                cout << 0 << '\n';
                return;
        }
        cout << 1 << " " << n - 1 << '\n';
        rep(i, n - 1) {
                cout << (long long) a[i] * (n - 1) << " \n"[i == n - 2];
        }
        cout << 2 << " " << n << '\n';
        rep(i, n) if (i) {
                if (i == n - 1) {
                        cout << (long long) a[i] * (n - 1) << '\n';
                } else {
                        cout << 0 << " ";
                }
        }
        cout << 1 << " " << n << '\n';
        rep(i, n) {
                cout << - (long long) a[i] * n << " \n"[i == n - 1];
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
