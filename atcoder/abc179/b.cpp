#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> d(n);
        rep(i, n) {
                cin >> d[i].first >> d[i].second;
        }
        rep(i, n - 2) {
                if (d[i].first == d[i].second &&
                    d[i + 1].first == d[i + 1].second &&
                    d[i + 2].first == d[i + 2].second) {
                        cout << "Yes" << '\n';
                        return;
                }
        }
        cout << "No\n";
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
