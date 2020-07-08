#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int acc = 0;
        int mi = 1e9 + 10;
        rep(i, n) {
                if (s[i] == '(') {
                        acc ++;
                } else {
                        acc --;
                }
                mi = min(mi, acc);
        }
        cout << mi * -1 << '\n';
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