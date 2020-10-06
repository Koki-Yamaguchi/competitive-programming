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
        vector<int> ans;
        while (true) {
                set<int> st;
                rep(i, n) {
                        st.insert(a[i]);
                }
                int mex = -1;
                rep(i, n + 1) {
                        if (st.count(i) == 0) {
                                mex = i;
                                break;
                        }
                }
                if (mex == n) {
                        bool cont = false;
                        rep(i, n) {
                                if (a[i] != i) {
                                        ans.push_back(i);
                                        a[i] = mex;
                                        cont = true;
                                        break;
                                }
                        }
                        if (cont) {
                                continue;
                        } else {
                                break;
                        }
                }
                assert(a[mex] != mex);
                ans.push_back(mex);
                a[mex] = mex;
        }
        assert(ans.size() <= 2 * n);
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i] + 1 << " ";
        }
        cout << '\n';
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
