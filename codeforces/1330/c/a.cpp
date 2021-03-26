#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        rep(i, m) {
                cin >> a[i];
        }
        int lima = 0;
        rep(i, m) {
                int limit = i + a[i] - 1;
                if (limit >= n) {
                        cout << -1 << '\n';
                        return;
                }
                lima = max(lima, limit);
        }
        int space = n - 1 - lima;
        vector<int> ans;
        int b = 0, e = 0;
        rep(i, m) {
                int ex = min({e - b, space, n - b - a[i]});
                space -= ex;
                ans.push_back(b + ex);
                // cerr << "b, e = " << b << " " << e << endl;
                e = b + ex + a[i];
                b = b + ex + 1;
        }
        if (space) {
                cout << -1 << '\n';
        } else {
                rep(i, m) {
                        cout << ans[i] + 1 << " \n"[i == m - 1];
                }
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
