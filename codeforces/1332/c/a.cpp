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
        vector<vector<char>> c((k + 1) / 2);
        rep(i, n) {
                int j = i % k;
                if (j < (k + 1) / 2) {
                        c[j].push_back(s[i]);
                } else {
                        c[k - j - 1].push_back(s[i]);
                }
        }
        int ans = 0;
        rep(i, (k + 1) / 2) {
                map<char, int> cnt;
                for (char ch : c[i]) {
                        cnt[ch] ++;
                }
                int ma = 0;
                for (auto it : cnt) {
                        ma = max(ma, it.second);
                }
                ans += (int) c[i].size() - ma;
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
