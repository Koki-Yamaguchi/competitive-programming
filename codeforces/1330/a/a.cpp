#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        set<int> st;
        rep(i, n) {
                cin >> a[i];
                st.insert(a[i]);
        }
        for (int v = 250; v >= 1; v --) {
                bool ok = true;
                int y = x;
                for (int i = 1; i <= v; i ++) {
                        if (st.count(i) > 0) {
                                continue;
                        } else if (y > 0) {
                                y --;
                        } else {
                                ok = false;
                                break;
                        }
                }
                if (ok) {
                        cout << v << '\n';
                        return;
                }
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
