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
        vector<bool> vl(n), vr(n);
        set<int> st;
        int ma = 0;
        rep(i, n) {
                if (st.count(a[i])) {
                        break;
                }
                st.insert(a[i]);
                ma = max(ma, a[i]);
                if (ma == i + 1) {
                        vl[i] = true;
                }
        }
        st.clear();
        ma = 0;
        for (int i = n - 1; i >= 0; i --) {
                if (st.count(a[i])) {
                        break;
                }
                st.insert(a[i]);
                ma = max(ma, a[i]);
                if (ma == n - i) {
                        vr[i] = true;
                }
        }
        vector<pair<int, int>> ans;
        rep(i, n - 1) {
                if (vl[i] && vr[i + 1]) {
                        ans.emplace_back(i + 1, n - i - 1);
                }
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i].first << " " << ans[i].second << '\n';
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
