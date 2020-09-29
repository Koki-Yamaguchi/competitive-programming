#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        map<char, int> cnt;
        rep(i, n) {
                string s;
                cin >> s;
                rep(j, s.size()) {
                        cnt[s[j]] ++;
                }
        }
        bool ok = true;
        for (auto it : cnt) {
                if (it.second % n != 0) {
                        ok = false;
                        break;
                }
        }
        cout << (ok ? "YES" : "NO") << '\n';
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
