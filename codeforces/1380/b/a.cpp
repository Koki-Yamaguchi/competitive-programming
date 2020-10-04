#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> cnt;
        rep(i, n) {
                cnt[s[i]] ++;
        }
        int ma = 0;
        char res = '*';
        for (auto it : cnt) {
                if (ma < it.second) {
                        ma = it.second;
                        res = it.first;
                }
        }
        if (res == 'R') res = 'P';
        else if (res == 'P') res = 'S';
        else res = 'R';
        rep(i, n) {
                cout << res;
        }
        cout << '\n';
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
