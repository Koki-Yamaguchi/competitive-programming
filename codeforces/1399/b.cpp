#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int ami = 1e9 + 10, bmi = 1e9 + 10;
        rep(i, n) {
                cin >> a[i];
                ami = min(ami, a[i]);
        }
        rep(i, n) {
                cin >> b[i];
                bmi = min(bmi, b[i]);
        }
        long long ans = 0;
        rep(i, n) {
                a[i] -= ami;
                b[i] -= bmi;
                int mi = min(a[i], b[i]);
                ans += mi;
                a[i] -= mi;
                b[i] -= mi;
                ans += a[i];
                ans += b[i];
        }
        cout << ans << '\n';
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
