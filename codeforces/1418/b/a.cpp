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
        vector<int> b(n);
        rep(i, n) {
                cin >> b[i];
        }
        vector<int> s;
        rep(i, n) {
                if (!b[i]) {
                        s.push_back(a[i]);
                }
        }
        sort(s.begin(), s.end());
        rep(i, n) {
                if (!b[i]) {
                        a[i] = s.back();
                        s.pop_back();
                }
        }
        rep(i, n) {
                cout << a[i] << " \n"[i == n - 1];
        }
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
