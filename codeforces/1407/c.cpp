#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

int ask(int i, int j) {
        cout << "? " << i << " " << j << endl;
        int res;
        cin >> res;
        return res;
}

void answer(const vector<int> &ans) {
        int n = ans.size();
        cout << "! ";
        rep(i, n) {
                if (i == n - 1) {
                        cout << ans[i] << endl;
                } else {
                        cout << ans[i] << " ";
                }
        }
}

void solve() {
        int n;
        cin >> n;
        int maidx = 1;
        vector<int> ans(n);
        rep(i, n) if (i) {
                int res0 = ask(maidx, i + 1);
                int res1 = ask(i + 1, maidx);
                if (res0 < res1) {
                        ans[i] = res1;
                } else {
                        ans[maidx - 1] = res0;
                        maidx = i + 1;
                }
        }
        ans[maidx - 1] = n;
        answer(ans);
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
