#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        long long lb = 0, ub = 1e18;
        while (ub - lb > 1) {
                long long mid = (lb + ub) / 2;
                long long v = mid - mid / n;
                if (v >= k) {
                        ub = mid;
                } else {
                        lb = mid;
                }
        }
        cout << ub << '\n';
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
