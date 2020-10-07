#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long f(vector<pair<int, int>> ps) {
        int n = ps.size();
        sort(ps.begin(), ps.end());
        long long ys = 0;
        rep(i, n) {
                ys += ps[i].second;
        }
        long long ymid = ys / n;
        long long top = -1;
        long long bottom = -1;
        long long res = 0;
        rep(i, n) {
                int x = ps[i].first;
                int y = ps[i].second;
                if (y <= ymid) {
                        if (top != -1) res = max(res, top + ymid - y);
                        bottom = max(bottom, ymid - y);
                }
                if (y >= ymid) {
                        if (bottom != -1) res = max(res, bottom + y - ymid);
                        top = max(top, y - ymid);
                }
                if (i != n - 1) {
                        int d = ps[i + 1].first - x;
                        if (top != -1) top += d;
                        if (bottom != -1) bottom += d;
                }
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> ps(n);
        rep(i, n) {
                cin >> ps[i].first >> ps[i].second;
        }
        long long ans = 0;
        ans = max(ans, f(ps));
        rep(i, n) {
                swap(ps[i].first, ps[i].second);
        }
        ans = max(ans, f(ps));
        cout << ans << '\n';
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
