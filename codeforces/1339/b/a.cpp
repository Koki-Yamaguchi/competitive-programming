#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        int l = 0, r = n - 1;
        vector<int> ans;
        while (l <= r) {
                ans.push_back(a[l]);
                if (l != r) ans.push_back(a[r]);
                l ++;
                r --;
        }
        reverse(all(ans));
        assert(ans.size() == n);
        rep(i, n) {
                cout << ans[i] << " \n"[i == n - 1];
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
