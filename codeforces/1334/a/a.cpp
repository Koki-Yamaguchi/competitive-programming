#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        rep(i, n) {
                cin >> a[i] >> b[i];
        }
        rep(i, n) {
                if (a[i] < b[i]) {
                        cout << "NO\n";
                        return;
                }
        }       
        rep(i, n - 1) {
                if (a[i] > a[i + 1] || b[i] > b[i + 1]) {
                        cout << "NO\n";
                        return;
                }
        }
        rep(i, n - 1) {
                if (a[i + 1] - a[i] < b[i + 1] - b[i]) {
                        cout << "NO\n";
                        return;
                }
        }
        cout << "YES\n";
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
