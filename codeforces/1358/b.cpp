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
        sort(a.begin(), a.end());
        int ans = -1;
        for (int i = n - 1; i >= 0; i --) {
                int c = i + 1;
                if (a[i] <= c) {
                        ans = i;
                        break;
                }
        }
        cout << ans + 2 << endl;
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
