#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        int cur = 0;
        rep(i, a) {
                s.push_back('a' + cur);
                if (i < b - 1) {
                        cur ++;
                }
        }
        string ans;
        rep(i, n) {
                ans.push_back(s[i % a]);
        }
        cout << ans << '\n';
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
