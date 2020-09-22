#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

// sub is subset of sup
bool is_subset(int sup, int sub) {
        rep(k, 10) {
                if ((sub >> k) & 1) {
                        if (!((sup >> k) & 1)) {
                                return false;
                        }
                }
        }
        return true;
}

void solve() {
        assert(is_subset(7, 0));
        assert(!is_subset(4, 3));
        assert(is_subset(5, 4));
        assert(is_subset(2, 2));

        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, m)  {
                cin >> b[i];
        }
        int ans = -1;
        rep(x, 1 << 9) {
                bool ok = true;
                rep(i, n) {
                        bool can = false;
                        rep(j, m) {
                                int c = a[i] & b[j];
                                can |= is_subset(x, c);
                        }
                        if (!can) {
                                ok = false;
                                break;
                        }
                }
                if (ok) {
                        ans = x;
                        break;
                }
        }
        cout << ans << '\n';
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
