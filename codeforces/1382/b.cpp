#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        int c = -1;
        rep(i, n) {
                cin >> a[i];
                if (a[i] > 1 && c == -1) {
                        c = i;
                }
        }
        if (c != -1) {
                if (c % 2 == 0) {
                        cout << "First" << '\n';
                } else {
                        cout << "Second" << '\n';
                }
        } else {
                if (n % 2 == 0) {
                        cout << "Second" << '\n';
                } else {
                        cout << "First" << '\n';
                }
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
