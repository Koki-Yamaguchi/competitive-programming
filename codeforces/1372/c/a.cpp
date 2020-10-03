#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        bool z = true;
        rep(i, n - 1) {
                z = z && (a[i] < a[i + 1]);
        }
        if (z) {
                cout << 0 << '\n';
                return;
        }
        bool f = false, ff = false;
        rep(i, n) {
                if (a[i] != i) {
                        f = true;
                }
                if (a[i] == i && f) {
                        ff = true;
                }
                if (a[i] != i && ff) {
                        cout << 2 << '\n';
                        return;
                }
        }
        cout << 1 << '\n';
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
