#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int h = y2 - y1;
        int w = x2 - x1;
        long long mi = (long long) h * (h - 1) / 2;
        long long ma = (long long) (h + w) * (h + w - 1) / 2 - (long long) w * (w - 1) / 2;
        cout << ma - mi + 1 << '\n';
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
