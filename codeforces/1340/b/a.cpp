#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

bool include(string sup, string sub) {
        rep(i, sup.size()) {
                if (sup[i] == '0' && sub[i] == '1') {
                        return false;
                }
        }
        return true;
}

int diff(string a, string b) {
        int res = 0;
        rep(i, a.size()) {
                res += a[i] != b[i];
        }
        return res;
}

void solve() {
        map<int, string> mp;
        mp[0] = "1110111";
        mp[1] = "0010010";
        mp[2] = "1011101";
        mp[3] = "1011011";
        mp[4] = "0111010";
        mp[5] = "1101011";
        mp[6] = "1101111";
        mp[7] = "1010010";
        mp[8] = "1111111";
        mp[9] = "1111011";
        int n, k;
        cin >> n >> k;
        vector<string> s(n);
        rep(i, n) {
                cin >> s[i];
        }
        const int sz = 16500;
        vector<bitset<sz>> can(n);
        for (int i = n - 1; i >= 0; i --) {
                rep(j, 10) {
                        if (include(mp[j], s[i])) {
                                if (i != n - 1) {
                                        can[i] |= (can[i + 1] << diff(s[i], mp[j]));
                                } else {
                                        can[i] |= (1 << diff(s[i], mp[j]));
                                }
                        }
                }
        }
        vector<int> ans(n, -1);
        int kkk = k;
        rep(i, n) {
                if (i != n - 1) {
                        for (int j = 9; j >= 0; j --) {
                                if (include(mp[j], s[i])) {
                                        int use = diff(s[i], mp[j]);
                                        int rest = kkk - use;
                                        string cans = can[i + 1].to_string();
                                        if (cans[(int) cans.size() - 1 - rest] == '1') {
                                                kkk -= use;
                                                ans[i] = j;
                                                break;
                                        }
                                }
                        }
                } else {
                        for (int j = 9; j >= 0; j --) {
                                if (include(mp[j], s[i]) && kkk - diff(s[i], mp[j]) == 0) {
                                        ans[i] = j;
                                        break;
                                }
                        }
                }
        }
        rep(i, n) {
                if (ans[i] == -1) {
                        cout << -1 << '\n';
                        return;
                }
        }
        int d = 0;
        rep(i, n) {
                d += diff(s[i], mp[ans[i]]);
        }
        assert(d == k);
        rep(i, n) {
                cout << ans[i];
        }
        cout << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
