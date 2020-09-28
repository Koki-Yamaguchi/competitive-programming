#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<long long> acc(n + 1, 0);
        rep(i, n) {
                acc[i + 1] = acc[i] + a[i];
        }
        set<long long> st;
        int ans = 0;
        rep(i, n + 1) {
                if (st.count(acc[i])) {
                        ans ++;
                        st.clear();
                        st.insert(acc[i - 1]);
                }
                st.insert(acc[i]);
        }
        cout << ans << '\n';
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
