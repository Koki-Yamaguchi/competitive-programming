#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        vector<int> a(3);
        rep(i, 3) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] == a[1]) {
                if (a[1] == a[2]) {
                        cout << "YES\n";
                        cout << a[0] << " " << a[1] << " " << a[2] << '\n';
                } else {
                        cout << "NO\n";
                }
        } else {
                if (a[1] == a[2]) {
                        cout << "YES\n";
                        cout << a[0] << " " << a[0] << " " << a[2] << '\n';
                } else {
                        cout << "NO\n";
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
