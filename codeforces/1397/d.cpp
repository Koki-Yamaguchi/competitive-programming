#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        int ma = 0;
        int sum = 0;
        rep(i, n) {
                cin >> a[i];
                ma = max(ma, a[i]);
                sum += a[i];
        }
        int others = sum - ma;
        if (ma > others) {
                cout << "T\n";
        } else {
                cout << (sum & 1 ? "T\n" : "HL\n");
        }
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
