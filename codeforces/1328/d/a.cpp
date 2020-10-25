#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        bool same = true;
        rep(i, n - 1) {
                if (a[i] != a[i + 1]) {
                        same = false;
                        break;
                }
        }
        if (same) {
                cout << 1 << '\n';
                rep(i, n) {
                        cout << 1 << ' ';
                }
                cout << '\n';
                return;
        }
        int idx = -1;
        rep(i, n) {
                if (a[i] == a[(i + 1) % n]) {
                        idx = i;
                        break;
                }
        }
        vector<int> ans(n);
        if (idx != -1) {
                bool f = false;
                for (int i = idx + 1; i  < idx + 1 + n; i ++) {
                        if (f) {
                                ans[i % n] = 1;
                        } else {
                                ans[i % n] = 2;
                        }
                        f = !f;
                }
                cout << 2 << '\n';
                rep(i, n) {
                        cout << ans[i] << ' ';
                }
                cout << '\n';
        } else {
                if (n & 1) {
                        cout << 3 << '\n';
                        rep(i, n) {
                                if (i == n - 1) {
                                        ans[i] = 3;
                                } else if (i & 1) {
                                        ans[i] = 1;
                                } else {
                                        ans[i] = 2;
                                }
                        }
                } else {
                        cout << 2 << '\n';
                        rep(i, n) {
                                if (i & 1) {
                                        ans[i] = 1;
                                } else {
                                        ans[i] = 2;
                                }
                        }
                }
                rep(i, n) {
                        cout << ans[i] << " ";
                }
                cout << '\n';
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
