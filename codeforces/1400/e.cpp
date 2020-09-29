#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

template <class T> constexpr T inf = numeric_limits<T>::max() / 2;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<int> dp(n + 1, inf<int>);
        dp[0] = 0;
        rep(i, n) {
                vector<int> nxt(n + 1, inf<int>);
                rep(j, n + 1) {
                        if (j <= a[i]) {
                                if (a[i] <= n) nxt[a[i]] = min(nxt[a[i]], dp[j] + a[i] - j);
                                nxt[j] = min(nxt[j], dp[j] + 1);
                        } else {
                                if (a[i] <= n) nxt[a[i]] = min(nxt[a[i]], dp[j]);
                        }
                }
                // rep(i, n + 1) cerr << nxt[i] << " "; cerr << endl;
                swap(dp, nxt);
        }
        cout << *min_element(dp.begin(), dp.end()) << '\n';

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
