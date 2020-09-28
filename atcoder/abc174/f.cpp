#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, q;
        cin >> n >> q;
        vector<int> c(n);
        rep(i, n) {
                cin >> c[i];
                c[i] --;
        }
        vector<pair<int, int>> qs(q);
        rep(i, q) {
                cin >> qs[i].first >> qs[i].second;
                qs[i].first --;
        }
        int nsqrt = sqrt(n);
        vector<int> qi(q);
        rep(i, q) qi[i] = i;
        sort(qi.begin(), qi.end(), [&](auto a, auto b) {
                int al = qs[a].first / nsqrt;
                int bl = qs[b].first / nsqrt;
                if (al == bl) {
                        if (al & 1) {
                                return qs[a].second > qs[b].second;
                        } else {
                                return qs[a].second < qs[b].second;
                        }
                }
                return al < bl;
        });
        int val = 0;
        vector<int> cnt(n);
        auto del = [&](int i) {
                cnt[c[i]] --;
                if (cnt[c[i]] == 0) val --;
        };
        auto add = [&](int i) {
                cnt[c[i]] ++;
                if (cnt[c[i]] == 1) val ++;
        };
        vector<int> ans(q);
        int l = 0, r = 0;
        rep(i, q) {
                int nl = qs[qi[i]].first;
                int nr = qs[qi[i]].second;
                while (nr < r) r --, del(r);
                while (nr > r) add(r), r ++;
                while (nl < l) l --, add(l);
                while (nl > l) del(l), l ++;
                ans[qi[i]] = val;
        }
        rep(i, q) {
                cout << ans[i] << '\n';
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}