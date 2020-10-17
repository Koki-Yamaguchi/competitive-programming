#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> cnt;
        vector<int> cyc;
        rep(i, n) {
                cin >> a[i];
                if (cnt.count(a[i]) == 0) cyc.push_back(a[i]);
                cnt[a[i]] ++;
        }
        if (cnt.size() > k) {
                cout << -1 << '\n';
                return;
        }
        while (cyc.size() < k) {
                cyc.push_back(1);
        }
        cout << n * k << '\n';
        rep(i, n) {
                rep(j, k) {
                        cout << cyc[j] << " ";
                }
        }
        cout << '\n';
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
