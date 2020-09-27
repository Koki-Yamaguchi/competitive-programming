#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int p, f;
        cin >> p >> f;
        int ca, cb;
        cin >> ca >> cb;
        int a, b;
        cin >> a >> b;
        if (a > b) {
                swap(a, b);
                swap(ca, cb);
        }
        int ans = 0;
        rep(x, ca + 1) {
                int res = 0;
                long long resta = ca, restb = cb;
                long long pp = p, ff = f;

                pp -= (long long) x * a;
                if (pp < 0) continue;
                res += x;
                resta -= x;

                int buyb = min((pp / b), restb);
                pp -= (long long) buyb * b;
                res += buyb;
                restb -= buyb;

                int buya = min((ff / a), resta);
                ff -= (long long) buya * a;
                res += buya;
                resta -= buya;

                res += min((ff / b), restb);

                // cerr << "res = " << res << endl;

                ans = max(ans, res);
        }
        cout << ans << '\n';
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
