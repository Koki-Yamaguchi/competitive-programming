#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        int oc = 0, ec = 0;
        rep(i, n) {
                cin >> a[i];
                if (a[i] & 1) {
                        oc ++;
                } else {
                        ec ++;
                }
        }
        bool ok = false;
        rep(i, n) {
                rep(j, i) {
                        if (abs(a[i] - a[j]) == 1) {
                                ok = true;
                        }
                }
        }
        if (ec % 2 == 0 || ok) {
                cout << "YES\n";
        } else {
                cout << "NO\n";
        }
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
