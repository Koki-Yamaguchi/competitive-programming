#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        for (int a = 0; a <= 1000; a ++) {
                for (int b = 0; b <= 1000; b ++) {
                        int rest = n - a * 3 - b * 5;
                        if (rest >= 0) { 
                                if (rest % 7 == 0) {
                                        cout << a << " " << b << " " << rest / 7 << '\n';
                                        return;
                                }
                        }
                }
        }
        cout << -1 << '\n';
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
