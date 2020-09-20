#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        bool ok = true;
        bool has = false;
        rep(i, n) {
                cin >> a[i];
                ok = ok && (a[i] == x);
                has = has || (a[i] == x);
        }
        if (ok) {
                cout << 0 << '\n';
                return;
        }
        int s = 0;
        rep(i, n) {
                s += x - a[i];
        }
        if (s == 0 || has) {
                cout << 1 << '\n';
        } else {
                cout << 2 << '\n';
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
