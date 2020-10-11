#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        long long s = 0;
        rep(i, k + 1) {
                s += a[i];
        }
        cout << s << '\n';
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
