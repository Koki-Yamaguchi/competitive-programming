#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<pair<ll, int>> xs(m);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, m) {
                cin >> xs[i].first;
                xs[i].second = i;
        }
        sort(all(xs));
        const ll inf = 1e18;
        vector<ll> acc(n), ma(n, -inf);
        acc[0] = a[0];
        ma[0] = a[0];
        rep(i, n) if (i) {
                acc[i] = acc[i - 1] + a[i];
                ma[i] = max(ma[i - 1], acc[i]);
        }
        ll d = acc[n - 1];
        ll md = ma[n - 1];
        ll gap = md - d;
        ll cur = 0;
        ll val = 0;
        vector<ll> ans(m, -1);
        if (d <= 0) {
                rep(i, m) {
                        auto [x, idx] = xs[i];
                        int pos = lower_bound(all(ma), x) - ma.begin();
                        if (pos < n) {
                                ans[idx] = pos;
                        }
                }
        } else {
                rep(i, m) {
                        auto [x, idx] = xs[i];
                        ll kyuri = x - cur - gap;
                        if (kyuri > d) {
                                ll cnt = (kyuri - 1) / d;
                                cur += cnt * d;
                                val += cnt * n;
                        }
                        assert(cur + md >= x);
                        ll diff = x - cur;
                        assert(diff >= 1);
                        int pos = lower_bound(all(ma), diff) - ma.begin();
                        assert(pos < n);
                        ans[idx] = val + pos;
                }
        }
        cout << ans << '\n';
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
