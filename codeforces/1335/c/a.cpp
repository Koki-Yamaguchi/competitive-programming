#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        rep(i, n) {
                cin >> a[i];
                cnt[a[i]] ++;
        }
        int k = cnt.size();
        int ans = 0;
        for (auto it : cnt) {
                int same = it.first;
                int samec = it.second;
                if (samec > 1) {
                        ans = max(ans, min(k, samec - 1));
                }
                ans = max(ans, min(k - 1, samec));
        }
        cout << ans << '\n';
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
