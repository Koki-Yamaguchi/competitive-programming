#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long gcd(long long a, long long b) {
        while (b) {
                a %= b;
                swap(a, b);
        }
        return a;
}

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        int ma = 0;
        int idx = -1;
        rep(i, n) {
                cin >> a[i];
                if (ma < a[i]) {
                        ma = a[i];
                        idx = i;
                }
        }
        vector<bool> used(n);
        vector<int> ans;
        ans.push_back(ma);
        used[idx] = true;

        int g = ma;
        while (true) {
                int maa = 0;
                rep(i, n) {
                        if (!used[i]) {
                                if (maa < gcd(g, a[i])) {
                                        maa = gcd(g, a[i]);
                                }
                        }
                }
                int cur = 1e9;
                int idxx = -1;
                rep(i, n) {
                        if (!used[i]) {
                                if (maa == gcd(g, a[i]) && cur > a[i]) {
                                        cur = a[i];
                                        idxx = i;
                                }
                        }
                }
                if (idxx == -1) {
                        break;
                }
                ans.push_back(cur);
                used[idxx] = true;
                g = gcd(g, a[idxx]);
        }
        assert(ans.size() == n);
        rep(i, n) {
                cout << ans[i] << " \n"[i == n - 1];
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
