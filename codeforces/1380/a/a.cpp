#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                bool l = false, r = false;
                int ll = -1, rr = -1;
                for (int j = i - 1; j >= 0; j --) {
                        if (a[j] < a[i]) {
                                l = true;
                                ll = j;
                                break;
                        }
                }
                for (int j = i + 1; j < n; j ++) {
                        if (a[j] < a[i]) {
                                r = true;
                                rr = j;
                                break;
                        }
                }
                if (l && r) {
                        cout << "YES\n";
                        cout << ll + 1 << " " << i + 1 << " " << rr + 1 << '\n';
                        return;
                }
        }
        cout << "NO\n";
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
