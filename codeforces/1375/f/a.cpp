#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        vector<long long> a(3);
        rep(i, 3) {
                cin >> a[i];
        }
        cout << "First" << endl;
        auto b = a;
        sort(b.begin(), b.end());
        long long y = b[2] * 2 - b[0] - b[1];
        cout << y << endl;
        int pos;
        cin >> pos;
        if (pos) {
                a[pos - 1] += y;
                b = a;
                sort(b.begin(), b.end());
                if (b[2] - b[1] == b[1] - b[0]) {
                        y = b[2] - b[1];
                } else {
                        y = b[2] * 2 - b[0] - b[1];
                }
                cout << y << endl;
                cin >> pos;
                if (pos) {
                        a[pos - 1] += y;
                        b = a;
                        sort(b.begin(), b.end());
                        assert(b[2] - b[1] == b[1] - b[0]);
                        y = b[2] - b[1];
                        cout << y << endl;
                        cin >> pos;
                        assert(pos == 0);
                }
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
