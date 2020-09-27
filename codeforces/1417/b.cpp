#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, t;
        cin >> n >> t;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        set<int> app;
        vector<int> color(n);
        int x = (t % 2 == 0 ? t / 2 : -1);
        bool f = true;
        rep(i, n) {
                if (a[i] == x) {
                        color[i] = f;
                        f = !f;
                        continue;
                }
                int comp = t - a[i];
                if (app.count(comp)) {
                        color[i] = 1;
                } else {
                        color[i] = 0;
                        app.insert(a[i]);
                }
        }
        rep(i, n) {
                cout << color[i] << " \n"[i == n - 1];
        }
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
