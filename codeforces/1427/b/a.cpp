#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

template <class S>
auto consecutive_element_count(const S& s) {
  vector<pair<typename S::value_type, int>> res;
  for (const auto& c : s)
    if (empty(res) or res.back().first != c)
      res.emplace_back(c, 1);
    else
      ++res.back().second;
  return res;
}

/*
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
*/

void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int c = 0;
        rep(i, n) {
                c += (s[i] == 'L');
        }
        if (c <= k) {
                cout << 2 * n - 1 << '\n';
                return;
        }
        if (c == n) {
                cout << max(0, 2 * k - 1) << '\n';
                return;
        }
        int ans = 0;
        rep(i, n) {
                if (s[i] == 'W') {
                        if (i == 0 || s[i - 1] == 'L') {
                                ans += 1;
                        } else {
                                ans += 2;
                        }
                }
        }
        auto cec = consecutive_element_count(s);
        if (cec[0].first == 'L') {
                cec[0].second += 200001;
        }
        if (cec[cec.size() - 1].first == 'L') {
                cec[cec.size() - 1].second += 200001;
        }
        sort(all(cec), [&](auto l, auto r) {
                return l.second < r.second;
        });
        rep(i, cec.size()) {
                if (cec[i].first == 'L') {
                        if (cec[i].second <= k) {
                                ans += (cec[i].second * 2 + 1);
                                k -= cec[i].second;
                                if (k == 0) {
                                        break;
                                }
                        } else if (k > 0) {
                                ans += k * 2;
                                break;
                        }
                }
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
