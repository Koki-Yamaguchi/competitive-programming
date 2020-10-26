#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int k; cin >> k;
        int p = 0;
        for (int i = 30; i >= 0; i --) {
                if ((k >> i) & 1) {
                        p = i;
                        break;
                }
        }
        cerr << "p = " << p << endl;
        int all = (1 << (p + 2)) - 1;
        int left = (1 << (p + 1)) - 1;
        int top = 1 << (p + 1);
        int mid = k | (1 << (p + 1));
        cout << 3 << " " << 3 << '\n';
        cout << all << " " << top << " " << 0 << '\n';
        cout << left << " " << mid << " " << left << '\n';
        cout << 0 << " " << left << " " << all << '\n';
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
