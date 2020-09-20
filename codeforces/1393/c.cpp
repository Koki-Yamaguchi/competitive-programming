#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int lb = 0, ub = n + 1;
        map<int, int> cnt;
        rep(i, n) {
                cnt[a[i]] ++;
        }
        vector<int> kinds;
        for (pair<int, int> c : cnt) {
                kinds.push_back(c.second);
        }
        sort(kinds.rbegin(), kinds.rend());
        while (ub - lb > 1) {
                int x = (lb + ub) / 2;
                int mi = n / (x + 1);
                int md = n % (x + 1);
                vector<int> l;
                rep(i, x + 1) {
                        int add = mi;
                        if (i < md) {
                                add ++;
                        }
                        l.push_back(add);
                }
                bool good = true;
                rep(i, l.size()) {
                        if (l[i] < kinds[i]) {
                                good = false;
                                break;
                        }
                }
                if (good) {
                        lb = x;
                } else {
                        ub = x;
                }
        }
        cout << lb << '\n';
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
