#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void f(string &s, int idx) {
        rep(i, idx + 1) {
                s[i] = s[i] == '1' ? '0' : '1';
        }
        int l = 0, r = idx;
        while (l < r) {
                swap(s[l], s[r]);
                l ++;
                r --;
        }
}

void solve() {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int e = n;
        while (a[e - 1] == b[e - 1]) {
                e --;
                if (e < 1) {
                        break;
                }
        }
        if (e == 0) {
                cout << 0 << '\n';
                return;
        }
        vector<int> ans;
        while (e) {
                bool fd = false;
                rep(i, e) {
                        if (a[i] == b[e - 1]) {
                                fd = true;
                                ans.push_back(i);
                                f(a, i);
                                f(a, e - 1);
                                ans.push_back(e - 1);
                                assert(a[e - 1] == b[e - 1]);
                                while (a[e - 1] == b[e - 1]) {
                                        e --;
                                        if (e < 1) {
                                                break;
                                        }
                                }
                                if (e < 1) {
                                        break;
                                }
                        }
                }
                if (!fd) {
                        ans.push_back(e - 1);
                        f(a, e - 1);
                        assert(a[e - 1] == b[e - 1]);
                        while (a[e - 1] == b[e - 1]) {
                                e --;
                                if (e < 1) {
                                        break;
                                }
                        }
                        if (e < 1) {
                                break;
                        }
                }
        }
        assert(a == b);
        cout << (int) ans.size() << " ";
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
