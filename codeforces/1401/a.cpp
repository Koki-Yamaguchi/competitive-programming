#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int a, k;
        cin >> a >> k;
        if (k <= a) {
                if ((a + k) % 2 == 0) {
                        cout << 0 << '\n';
                } else {
                        cout << 1 << '\n';
                }
        } else {
                cout << k - a << '\n';
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
