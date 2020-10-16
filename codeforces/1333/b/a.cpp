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
                cin >> a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        int incl = n, decl = n;
        rep(i, n) {
                if (a[i] < b[i]) {
                        incl = min(incl, i);
                }
                if (a[i] > b[i]) {
                        decl = min(decl, i);
                }
        }
        bool incok = (incl == n), decok = (decl == n);
        for (int i = 0; i < incl; i ++) {
                incok = incok || (a[i] == 1);
        }
        for (int i = 0; i < decl; i ++) {
                decok = decok || (a[i] == -1);
        }
        cout << (incok && decok ? "YES" : "NO") << '\n';
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
