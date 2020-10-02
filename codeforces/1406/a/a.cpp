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
        sort(a.begin(), a.end());
        vector<int> s, t;
        rep(i, n) {
                if (i == 0 || a[i] != a[i - 1]) {
                        s.push_back(a[i]);
                } else {
                        t.push_back(a[i]);
                }
        }
        auto mex = [&](vector<int> &v) {
                set<int> st;
                rep(i, v.size()) {
                        st.insert(v[i]);
                }
                rep(i, 101) {
                        if (st.count(i) == 0) {
                                return i;
                        }
                }
                assert(false);
                return 0;
        };
        int ans = mex(s) + mex(t);
        cout << ans << "\n";
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
