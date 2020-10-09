#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (((a == c && b + d == a) || (a == d && b + c == a) || (b == c && a + d == b) || (b == d && a + c == b)) ? "Yes" : "No") << "\n";
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
