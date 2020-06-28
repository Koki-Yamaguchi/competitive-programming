#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long sum(int x) { // [1, x]
        long long res = (long long) (x + 1) * x / 2;
        return res;
}

void solve() {
        int n;
        long long x;
        cin >> n >> x;
        vector<int> d(n * 2);
        rep(i, n) {
                cin >> d[i];
        }
        rep(i, n) {
                d[i + n] = d[i];
        }
        n *= 2;
        reverse(d.begin(), d.end());
        vector<long long> acc(n);
        acc[0] = d[0];
        for (int i = 1; i < n; i ++) {
                acc[i] = acc[i - 1] + d[i];
        }
        vector<long long> sumacc(n);
        sumacc[0] = sum(d[0]);
        for (int i = 1; i < n; i ++) {
                sumacc[i] = sumacc[i - 1] + sum(d[i]);
        }
        long long ans = 0;
        rep(i, n) {
                long long p = i > 0 ? acc[i - 1] : 0;
                p += x;
                int pos = lower_bound(acc.begin(), acc.end(), p) - acc.begin();
                if (pos == n) {
                        continue;
                }
                int r = acc[pos] - p;
                assert(d[pos] - r >= 0);
                r = d[pos] - r;
                long long gezan = sum(d[pos]) - sum(d[pos] - r);
                long long tozan = (pos > 0 ? sumacc[pos - 1] : 0) - (i > 0 ? sumacc[i - 1] : 0);
                ans = max(ans, tozan + gezan);
        }
        cout << ans << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t = 1;
        // cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
