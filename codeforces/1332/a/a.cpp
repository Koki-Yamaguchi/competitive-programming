#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int x, y, x0, y0, x1, y1;
        cin >> x >> y >> x0 >> y0 >> x1 >> y1;
        int dx0 = x - x0;
        int dx1 = x1 - x;
        int dy0 = y - y0;
        int dy1 = y1 - y;
        if (x0 == x1 && (a != 0 || b != 0)) {
                cout << "No\n";
                return;
        }
        if (max(0, a - b) > dx0) {
                cout << "No\n";
                return;
        }
        if (max(0, b - a) > dx1) {
                cout << "No\n";
                return;
        }
        if (y0 == y1 && (c != 0 || d != 0)) {
                cout << "No\n";
                return;
        }
        if (max(0, c - d) > dy0) {
                cout << "No\n";
                return;
        }
        if (max(0, d - c) > dy1) {
                cout << "No\n";
                return;
        }
        cout << "Yes\n";
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
