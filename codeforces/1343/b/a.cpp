#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long n;
        cin >> n;
        if (n % 4 == 0) {
                cout << "YES\n";
                long long s = 0;
                for (int i = 2; i <= n; i += 2) {
                        s += i;
                        cout << i << " ";
                }
                long long t = 0;
                for (int i = 1; i <= n - 2; i += 2) {
                        t += i;
                        cout << i << " ";
                }
                cout << s - t << '\n';
        } else {
                cout << "NO\n";
        }
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
