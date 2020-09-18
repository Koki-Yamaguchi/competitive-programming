#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        if (n < 31) {
                cout << "NO\n";
        } else {
                cout << "YES\n";
                if (n == 36) {
                        cout << "5 6 10 15\n";
                } else if (n == 40) {
                        cout << "6 10 15 9\n";
                } else if (n == 44) {
                        cout << "6 10 21 7\n";
                } else {
                        int r = n - 6 - 10 - 14;
                        assert(r != 6 && r != 10 && r != 14);
                        cout << "6 10 14 " << r << "\n";
                }
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
