#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int m = 6;
        vector<int> b(m);
        rep(i, m) {
                cin >> b[i];
        }
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<pair<int, int>> val;
        rep(i, n) {
                rep(j, m) {
                        val.emplace_back(a[i] - b[j], i);
                }
        }
        sort(all(val));
        map<int, int> cnt;
        int k = 0;
        int l = 0, r = 0;
        int ans = 1e9;
        while (true) {
                while (r < n * m && k < n) {
                        cnt[val[r].second] ++;
                        if (cnt[val[r].second] == 1) {
                                k ++;
                        }
                        r ++;
                }
                if (r == n * m) {
                        break;
                }
                while (k == n) {
                        ans = min(ans, val[r - 1].first - val[l].first);
                        cnt[val[l].second] --;
                        if (cnt[val[l].second] == 0) {
                                k --;
                        }
                        l ++;
                }
        }
        cout << ans << '\n';
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
