#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

vector<int> f(const vector<int> &a, const vector<int> &b) {
        int n = a.size();
        if (n == 1) {
                if (a[0] != b[0]) {
                        return { b[0] };
                } else {
                        return { -1 };
                }
        }
        int cur = 0;
        vector<int> rest;
        vector<int> res;
        int idx = -1;
        rep(i, n) {
                while (cur < n && a[i] == b[cur]) {
                        rest.push_back(b[cur]);
                        cur ++;
                }
                if (cur == n) {
                        idx = i;
                        break;
                } else {
                        res.push_back(b[cur]);
                        cur ++;
                }
        }
        if (idx == -1) {
                return res;
        } else if (res.size() == 0) {
                vector<int> hoge(n, -1);
                return hoge;
        }
        vector<int> rrr;
        for (int i = idx; i < n; i ++) {
                rrr.push_back(a[i]);
        }
        assert(rrr.size() == rest.size());
        auto rrrr = f(rrr, rest);
        rep(i, rrrr.size()) {
                res.push_back(rrrr[i]);
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        vector<int> ans = f(a, b);
        rep(i, ans.size()) {
                if (ans[i] == -1) {
                        cout << "No\n";
                        return;
                }
        }
        cout << "Yes\n";
        rep(i, n) {
                cout << ans[i] << " \n"[i == n - 1];
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
