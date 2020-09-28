#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(3), b(3);
        rep(i, 3) {
                cin >> a[i];
        }
        rep(i, 3) {
                cin >> b[i];
        }
        int ansma = 0;
        rep(i, 3) {
                ansma += min(a[i], b[(i + 1) % 3]);
        }
        int ansmi = 0;
        rep(i, 3) {
                int r = max(0, a[i] - (b[(i + 2) % 3] + b[i]));
                ansmi += r;
        }
        cout << ansmi << " " << ansma << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
