#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, x;
        cin >> n >> x;
        if (n == 1 || n == 2) {
                cout << 1 << '\n';
        } else {
                cout << ((n - 2 + x - 1) / x) + 1 << '\n';
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
