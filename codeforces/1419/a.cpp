#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> r, b;
        rep(i, n) {
                if (i & 1) {
                        b.push_back(s[i] - '0');
                } else {
                        r.push_back(s[i] - '0');
                }
        }
        if (b.size() >= r.size()) {
                bool inc_even = false;
                for (int i = 0; i < b.size(); i ++) {
                        inc_even = inc_even || (b[i] % 2 == 0);
                }
                if (inc_even) {
                        cout << 2 << '\n';
                } else {
                        cout << 1 << '\n';
                }
        } else {
                bool inc_odd = false;
                rep(i, r.size()) {
                        inc_odd = inc_odd || (r[i] & 1);
                }
                if (inc_odd) {
                        cout << 1 << '\n';
                } else {
                        cout << 2 << '\n';
                }
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
