#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long calc(vector<int> &a) {
        int n = a.size();
        long long res = 0;
        for (int i = 1; i < n - 1; i ++) {
                if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                        res += a[i];
                }
                if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
                        res -= a[i];
                }
        }
        return res;
}

long long f3(vector<int> &a, int m, int idx) {
        int sz = a.size();
        int ll = idx >= 2 ? a[idx - 2] : 0;
        int  l = a[idx - 1];
        int  r = a[idx + 1];
        int rr = (idx + 2 < sz ? a[idx + 2] : 0);
        vector<int> v = {ll, l, m, r, rr};
        return calc(v);
}

long long f2(vector<int> &a, int l, int r, int idx) {
        int sz = a.size();
        int lll = idx >= 3 ? a[idx - 3] : 0;
        int ll  = a[idx - 2];
        int   m = a[idx];
        int rr  = a[idx + 2];
        int rrr = (idx + 3 < sz ? a[idx + 3] : 0);
        vector<int> v = {lll, ll, l, m, r, rr, rrr};
        return calc(v);
}

int f1(vector<int> &a, int l, int r, int lidx) {
        int ridx = lidx + 1;
        int sz = a.size();
        int lll = lidx >= 2 ? a[lidx - 2] : 0;
        int ll  = a[lidx - 1];
        int rr  = a[ridx + 1];
        int rrr = (ridx + 2 < sz ? a[ridx + 2] : 0);
        vector<int> v = {lll, ll, l, r, rr, rrr};
        return calc(v);
}

void solve() {
        int n, q;
        cin >> n >> q;
        vector<int> a;
        a.push_back(0);
        rep(i, n) {
                int b;
                cin >> b;
                a.push_back(b);
        }
        a.push_back(0);
        long long ans = calc(a);
        cout << ans << '\n';
        while (q --) {
                int s, t;
                cin >> s >> t;
                if (s > t) swap(s, t);
                if (t - s >= 3) {
                        ans -= f3(a, a[s], s);
                        ans += f3(a, a[t], s);
                        ans -= f3(a, a[t], t);
                        ans += f3(a, a[s], t);
                } else if (t - s == 2) {
                        ans -= f2(a, a[s], a[t], (s + t) / 2);
                        ans += f2(a, a[t], a[s], (s + t) / 2);
                } else if (t - s == 1) {
                        ans -= f1(a, a[s], a[t], s);
                        ans += f1(a, a[t], a[s], s);
                } else {
                        assert(false);
                }
                cout << ans << '\n';
                swap(a[s], a[t]);
        }

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
