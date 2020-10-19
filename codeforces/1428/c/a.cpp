#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        string s; cin >> s;
        int ac = 0, dc = 0;
        int n = s.size();
        vector<bool> del(n);
        rep(i, n) {
                if (s[i] == 'A') {
                        ac ++;
                } else {
                        if (ac) {
                                ac --;
                                del[i] = true;
                                dc ++;
                        }
                }
        }
        int bc = 0;
        rep(i, n) {
                if (!del[i] && s[i] == 'B') {
                        bc ++;
                }
        }
        cout << n - (dc * 2 + (bc / 2) * 2) << '\n';
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
