#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        rep(i, n) {
                cin >> a[i].first;
                a[i].second = i;
        }
        vector<pair<int, int>> ans;
        rep(j, n) {
                rep(i, j) {
                        if (a[i].first > a[j].first) {
                                ans.emplace_back(i, j);
                        }
                }
        }
        sort(ans.begin(), ans.end(), [&](pair<int, int> s, pair<int, int> t) {
                if (s.second != t.second) {
                        return s.second > t.second;
                }
                return a[s.first] < a[t.first];
        });
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
