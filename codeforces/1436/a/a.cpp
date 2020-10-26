#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        ll s = 0;
        rep(i, n) {
                cin >> a[i];
                s += a[i];
        }
        if (s == m) {
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
