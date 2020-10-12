#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long n;
        cin >> n;
        long long b = 1;
        long long cur = 2;
        while (true) {
                b += cur;
                if (n % b == 0) {
                        cout << n / b << '\n';
                        return;
                }
                cur *= 2;
        }
        assert(false);
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
