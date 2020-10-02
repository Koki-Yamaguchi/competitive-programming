#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long l, r;
        cin >> l >> r;
        long long m;
        cin >> m;
        for (int a = l; a <= r; a ++) {
                long long ma = m + (r - l);
                long long mi = m - (r - l);
                long long mad = ma / a;
                long long mid = (mi - 1) / a;
                if (mad != mid) {
                        long long t = mad * a;
                        long long mv = t - mi;
                        long long db = min(mv, r - l);
                        mv -= db;
                        long long b = r - db;
                        long long c = l;
                        if (mv) {
                                long long dc = mv;
                                c += dc;
                        }
                        assert(l <= b && b <= r && l <= c && c <= r);
                        cout << a << " " << b << " " << c << '\n';
                        return;
                }
        }
        assert(false);
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
