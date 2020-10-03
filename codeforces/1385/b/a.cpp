#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        set<int> st;
        vector<int> ans;
        rep(i, 2 * n) {
                int a;
                cin >> a;
                if (st.count(a)) continue;
                st.insert(a);
                ans.push_back(a);
        }
        rep(i, n) cout << ans[i] << " \n"[i == n - 1];
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
