#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> used(n);
        rep(i, n) {
                cin >> a[i];
                used[(i + ((a[i] % n) + n)) % n] = true;
        }
        bool ok = true;
        rep(i, n) {
                ok = ok && used[i];
        }
        cout << (ok ? "YES" : "NO") << '\n';
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
