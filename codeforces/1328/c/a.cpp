#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n; cin >> n;
        string s; cin >> s;
        string ans0, ans1;
        bool f = false;
        rep(i, n) {
                if (s[i] == '0') {
                        ans0.push_back('0');
                        ans1.push_back('0');
                } else if (s[i] == '1') {
                        if (f) {
                                ans0.push_back('0');
                                ans1.push_back('1');
                        } else {
                                ans0.push_back('1');
                                ans1.push_back('0');
                        }
                        f = true;
                } else if (s[i] == '2') {
                        if (f) {
                                ans0.push_back('0');
                                ans1.push_back('2');
                        } else {
                                ans0.push_back('1');
                                ans1.push_back('1');
                        }
                }
        }
        cout << ans0 << '\n' << ans1 << '\n';
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
