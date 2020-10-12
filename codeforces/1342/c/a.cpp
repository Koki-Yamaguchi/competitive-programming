#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long a, b, q;
        cin >> a >> b >> q;
        vector<long long> v(a * b);
        long long c = 0;
        rep(x, a * b) {
                long long p = (x % a % b != x % b % a);
                c += p;
                v[x] = p;
        }
        vector<long long> acc(a * b);
        acc[0] = v[0];
        rep(i, a * b) if (i) {
                acc[i] = acc[i - 1] + v[i];
        }
        auto get = [&](long long p) {
                long long res = (p / (a * b)) * c;
                res += acc[p % (a * b)];
                return res;
        };
        rep(i, q) {
                long long l, r;
                cin >> l >> r;
                long long ans = get(r) - get(l - 1);
                cout << ans << " \n"[i == q - 1];
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
