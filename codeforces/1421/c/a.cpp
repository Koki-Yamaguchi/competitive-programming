#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        // ab  ...S
        // bab ...S
        // bab ...S ...S' ba
        // bab ...S ...S' bab
        string s; cin >> s;
        int n = s.size();
        cout << 3 << '\n';
        cout << "L " << 2 << '\n';
        n += 1;
        cout << "R " << 2 << '\n';
        n += n - 2;
        cout << "R " << n - 1 << '\n';
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
