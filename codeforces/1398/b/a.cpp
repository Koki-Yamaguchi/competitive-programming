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
        string s; cin >> s;
        auto e = consecutive_element_count(s.begin(), s.end());
        vector<int> v;
        for (pair<char, int> p : e) {
                if (p.first == '1') {
                        v.push_back(p.second);
                }
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        rep(i, v.size()) {
                if (i % 2 == 0) {
                        ans += v[i];
                }
        }
        cout << ans << '\n';
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
