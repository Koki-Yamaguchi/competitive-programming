#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a, b;
        int tot = 0;
        vector<int> ans(n);
        rep(i, n) {
                if (s[i] == '1') {
                        if (b.size() > 0) {
                                int v = b.back();
                                b.pop_back();
                                ans[i] = v;
                                a.push_back(v);
                        } else {
                                tot ++;
                                ans[i] = tot;
                                a.push_back(tot);
                        }
                } else {
                        if (a.size() > 0) {
                                int v = a.back();
                                a.pop_back();
                                ans[i] = v;
                                b.push_back(v);
                        } else {
                                tot ++;
                                ans[i] = tot;
                                b.push_back(tot);
                        }
                }
        }
        cout << tot << '\n';
        rep(i, n) {
                cout << ans[i] << " ";
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
