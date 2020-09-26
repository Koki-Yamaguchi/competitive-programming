#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        int mi = 1e9 + 5;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                mi = min(mi, a[i]);
        }
        vector<bool> can_move(n);
        vector<int> tmp;
        rep(i, n) {
                if (a[i] % mi == 0) {
                        can_move[i] = true;
                        tmp.push_back(a[i]);
                }
        }
        sort(tmp.rbegin(), tmp.rend());
        rep(i, n) {
                if (can_move[i]) {
                        assert(tmp.size());
                        a[i] = tmp.back();
                        tmp.pop_back();
                }
        }
        rep(i, n - 1) {
                if (a[i] > a[i + 1]) {
                        cout << "NO" << '\n';
                        return;
                }
        }
        cout << "YES" << '\n';
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
