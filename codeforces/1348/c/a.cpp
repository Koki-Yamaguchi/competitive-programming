#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(all(s));
        rep(i, k - 1) {
                if (s[i] != s[i + 1]) {
                        cout << s[i + 1] << '\n';
                        return;
                }
        }
        for (int i = k; i < n - 1; i ++) {
                if (s[i] != s[i + 1]) {
                        cout << s[0] << s.substr(k, n - k) << '\n';
                        return;
                }
        }
        if (n == k) {
                cout << s[0] << '\n';
                return;
        }
        string suf = string((n - k + k - 1) / k, s[k]);
        cout << s[0] << suf << '\n';
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
