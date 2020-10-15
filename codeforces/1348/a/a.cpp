#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n;
        cin >> n;
        ll b = 2;
        int cnt = n;
        vector<ll> v;
        ll s = 0;
        while (cnt --) {
                s += b;
                v.push_back(b);
                b *= 2;
        }
        ll l = 0;
        for (int i = n - 2; i >= n / 2 - 1; i --) {
                l += v[i];
        }
        cout << abs(l - (s - l)) << '\n';
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
