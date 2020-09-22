#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        vector<int> a(4);
        int oc = 0;
        rep(i, 4) {
                cin >> a[i];
                oc += (a[i] & 1);
        }
        if (oc <= 1) {
                cout << "Yes" << '\n';
        } else if (oc == 2) {
                cout << "No" << '\n';
        } else {
                if (a[0] >=1 && a[1] >= 1 && a[2] >= 1) {
                        cout << "Yes" << '\n';
                } else {
                        cout << "No" << '\n';
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
