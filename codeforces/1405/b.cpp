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
        long long cur = 0, ans = 0;
        rep(i, n) {
                if (a[i] > 0) {
                        cur += a[i];
                } else {
                        cur += a[i];
                        if (cur < 0) {
                                ans += -cur;
                                cur = 0;
                        }
                }
                /*
                cerr << "ans = " << ans << endl;
                cerr << "cur = " << cur << endl;
                */
        }
        cout << ans << '\n';
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
