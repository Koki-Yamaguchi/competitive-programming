#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        string s;
        cin >> s;
        int y = 0, x = 0;
        set<pair<pair<int, int>, pair<int, int>>> st;
        int ans = 0;
        rep(i, s.size()) {
                int ny = y, nx = x;
                if (s[i] == 'S') ny --;
                if (s[i] == 'N') ny ++;
                if (s[i] == 'W') nx --;
                if (s[i] == 'E') nx ++;
                if (st.count(minmax(make_pair(y, x), make_pair(ny, nx)))) {
                        ans += 1;
                } else {
                        ans += 5;
                }
                st.insert(minmax(make_pair(y, x), make_pair(ny, nx)));
                x = nx;
                y = ny;
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
