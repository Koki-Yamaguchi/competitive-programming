#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n / 2), b(n / 2);
        rep(i, n / 2) {
                cin >> a[i];
        }
        rep(i, n / 2) {
                cin >> b[i];
        }
        reverse(b.begin(), b.end());
        n /= 2;
        vector<int> cnt(2 * k + 2);
        rep(i, n) {
                int u = min(a[i], b[i]);
                int v = max(a[i], b[i]);
                cnt[0] += 2;
                cnt[u + 1] -= 1;
                cnt[u + v] -= 1;
                cnt[u + v + 1] += 1;
                cnt[v + k + 1] += 1;
        }
        rep(i, 2 * k + 2) if (i) {
                cnt[i] += cnt[i - 1];
        }
        cout << *min_element(cnt.begin(), cnt.end()) << '\n';
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
