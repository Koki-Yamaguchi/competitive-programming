#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

template<class Iterator> auto consecutive_element_count(Iterator first, Iterator last) {
        vector<pair<decltype(*first), int>> cnt;
        auto it = first;
        while (it != last) {
                if (cnt.empty() || cnt.back().first != *it) {
                        cnt.emplace_back(*it, 1);
                } else {
                        cnt.back().second ++;
                }
                it ++;
        }
        return cnt;
}

void solve() {
        /*
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cc = 0;
        rep(i, n) if (i) {
                if (s[i] == s[i - 1]) {
                        cc ++;
                }
        }
        cerr << "cc = "<< cc << endl;
        int nc = n - cc;
        if (cc >= nc) {
                cout << nc << '\n';
        } else {
                int ans = cc;
                int r = n - 2 * cc;
                ans += (r + 1) / 2;
                cout << ans << '\n';
        }
        */
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto cec = consecutive_element_count(s.begin(), s.end());
        int ans = 0;
        int cur = 0;
        bool b = false;
        rep(i, cec.size()) {
                while (!b && cur < (int) cec.size() - 1 && (i > cur || cec[cur].second == 1)) {
                        cur ++;
                }
                if (cec[cur].second >= 2) {
                        cec[cur].second --;
                } else {
                        b = true;
                        cur --;
                }
                ans ++;
                if (b && i >= cur) break;
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
