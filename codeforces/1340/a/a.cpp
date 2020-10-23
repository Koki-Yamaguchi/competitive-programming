#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                a[i] --;
        }
        vector<int> res, tmp;
        for (int i = n - 1; i >= 0; i --) {
                if (i == n - 1 || a[i] < a[i + 1]) {
                        tmp.push_back(a[i]);
                } else {
                        reverse(all(tmp));
                        rep(j, tmp.size()) {
                                res.push_back(tmp[j]);
                        }
                        tmp = {a[i]};
                }
        }
        reverse(all(tmp));
        rep(j, tmp.size()) {
                res.push_back(tmp[j]);
        }
        rep(i, n) {
                if (res[i] != i) {
                        cout << "No\n";
                        return;
                }
        }
        cout << "Yes\n";
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
