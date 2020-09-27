#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0;
        rep(i, n) {
                cin >> a[i];
                sum += a[i];
        }
        if (sum % n != 0) {
                cout << -1 << '\n';
                return;
        }
        long long target = sum / n;
        vector<pair<int, pair<int, long long>>> ans;
        for (int i = 1; i < n; i ++) {
                int idx = i + 1;
                if (a[i] % idx != 0) {
                        int x = idx - (a[i] % idx);
                        assert(a[0] >= x);
                        a[0] -= x;
                        a[i] += x;
                        ans.emplace_back(0, make_pair(i, x));
                }
                assert(a[i] % idx == 0);
                int d = a[i] / idx;
                a[i] -= d * idx;
                a[0] += d * idx;
                ans.emplace_back(i, make_pair(0, d));
        }
        for (int i = 1; i < n; i ++) {
                ans.emplace_back(0, make_pair(i, target));
        }
        assert(ans.size() <= 3 * n);
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i].first + 1 << " " << ans[i].second.first + 1 << " " << ans[i].second.second << '\n';
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
