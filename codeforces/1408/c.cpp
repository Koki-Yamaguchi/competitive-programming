#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long double f(const vector<long long> &x, long double t) {
        long long cur = 0;
        long long v = 1;
        long double rest = t;
        long double d = 0.0;
        rep(i, x.size()) if (i) {
                long double nt = (long double) (x[i] - cur) / v;
                if (nt < rest) {
                        v ++;
                        d += x[i] - cur;
                        cur = x[i];
                        rest -= nt;
                } else {
                        d += rest * v;
                        return d;
                }
        }
        return x.back();
}

void solve() {
        long long n, l;
        scanf("%lld%lld", &n, &l);
        vector<long long> x;
        x.push_back(0);
        rep(i, n) {
                int tmp;
                scanf("%d", &tmp);
                x.push_back(tmp);
        }
        x.push_back(l);
        vector<long long> rx;
        rep(i, n + 2) {
                rx.push_back(l - x[i]);
        }
        reverse(rx.begin(), rx.end());

        int c = 100;
        long double lb = 0.0, ub = 1e9 + 5;
        while (c --) {
                long double m = (lb + ub) / 2;
                long double p = f(x, m);
                long double q = f(rx, m);
                // cerr << "m, p, q = " << m << " " << p << " " << q << endl;
                if (p + q > l) {
                        ub = m;
                } else {
                        lb = m;
                }
        }
        printf("%.15Lf\n", lb);
}

int main() {
        int t;
        scanf("%d", &t);
        while (t --) {
                solve();
        }
        return 0;
}
