#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        ll s = 0;
        rep(i, n) {
                cin >> a[i];
                s += a[i];
        }
        if (s == 0) {
                cout << "NO\n";
                return;
        }
        cout << "YES\n";
        sort(all(a));
        if (s > 0) {
                reverse(all(a));
        }
        rep(i, n) {
                cout << a[i] << " \n"[i == n - 1];
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
