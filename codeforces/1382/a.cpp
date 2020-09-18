#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        set<int> s;
        rep(i, n) {
                int a;
                cin >> a;
                s.insert(a);
        }
        bool ok = false;
        vector<int> b(m);
        rep(i, m) {
                cin >> b[i];
        }
        rep(i, m) {
                if (s.count(b[i])) {
                        cout << "YES" << '\n';
                        cout << 1 << " " << b[i] << '\n';
                        ok = true;
                        break;
                }
        }
        if (!ok) {
                cout << "NO" << '\n';
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
