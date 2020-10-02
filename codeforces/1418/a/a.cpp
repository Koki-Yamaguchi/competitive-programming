#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int x, y, k;
        cin >> x >> y >> k;
        long long ne = (long long) y * k;
        cout << k + (ne + k - 1 + x - 2) / (x - 1) << '\n';
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
