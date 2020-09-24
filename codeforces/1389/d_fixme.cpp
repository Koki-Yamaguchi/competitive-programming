#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long calc(int n, int l0, int r0, int l1, int r1, long long x) {
        int l = l1 - r0;
        if (l <= 0) {
                int c = r0 - l1;
                long long inc = r0 - l0 - c + r1 - l1 - c;
                if (x <= inc * n) {
                        return x;
                } else {
                        return inc * n + (x - inc * n) / 2;
                }
        } else {
                if (x < l) {
                        return 0;
                } else {
                        x -= l;
                        long long L = r1 - l0;
                        if (x < L) {
                                return x;
                        } else {
                                long long res = 0;
                                x -= L;
                                res += L;

                                while (n --) {
                                        if (x < l) {
                                                return res + x / 2;
                                        }
                                        if ((l + min(L, x - l)) / 2 > min(L, x - l)) {
                                                return res + x / 2;
                                        } else {
                                                long long got = min(L, x - l);
                                                res += got;
                                                x -= l + min(L, x - l);
                                        }
                                }

                                return res + x / 2;
                        }
                }
        }
}

void solve() {
        int n, k;
        cin >> n >> k;
        int l0, r0, l1, r1;
        cin >> l0 >> r0 >> l1 >> r1;
        if (l0 >l1) {
                swap(l0, l1);
                swap(r0, r1);
        }

        long long lb = 0, ub = 1e10;
        while (ub - lb > 1) {
                long long x = (lb + ub) / 2;
                if (k <= calc(n, l0, r0, l1, r1, x)) {
                        ub = x;
                } else {
                        lb = x;
                }
        }
        cout << lb << "\n";
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
