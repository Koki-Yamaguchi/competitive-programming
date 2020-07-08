#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> tmp(n), a;
        rep(i, n) {
                cin >> tmp[i];
                if (tmp[i] % k != 0) {
                        a.push_back(tmp[i]);
                }
        }
        if (a.size() == 0) {
                cout << 0 << '\n';
                return;
        }
        n = a.size();
        map<int, int> cnt;
        rep(i, n) {
                cnt[a[i] % k] ++;
        }
        int l = 0;
        for (auto it : cnt) {
                l = max(l, it.second);
        }
        int mi = 1e9 + 5;
        for (auto it : cnt) {
                if (l == it.second) {
                        mi = min(mi, it.first);
                }
        }
        cout << (long long) l * k - mi + 1 << '\n';
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