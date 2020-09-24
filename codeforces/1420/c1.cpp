#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, q;
        cin >> n >> q;
        vector<int> a;
        a.push_back(0);
        rep(i, n) {
                int b;
                cin >> b;
                a.push_back(b);
        }
        a.push_back(0);
        long long ans = 0;
        for (int i = 1; i <= n; i ++) {
                if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                        ans += a[i];
                }
                if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
                        ans -= a[i];
                }
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
