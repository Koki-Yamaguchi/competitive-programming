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
        sort(a.begin(), a.end());
        bool ok = true;
        rep(i, n - 1) {
                if (abs(a[i] - a[i + 1]) > 1) {
                        ok = false;
                        break;
                }
        }
        puts(ok ? "YES" : "NO");
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
