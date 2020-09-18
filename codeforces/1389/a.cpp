#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int l, r;
        cin >> l >> r;
        if (r & 1) r --;
        int m = r / 2;
        if (l <= m && m <= r) {
                cout << m << " " << r << endl;
        } else {
                cout << -1 << " " << -1 << endl;
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
