#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        rep(i, n) {
                cin >> a[i].first;
                a[i].second = i;
        }
        int inv = 0;
        bool mult = false;
        rep(r, n) rep(l, r) {
                inv += a[l] > a[r];
                if (a[l].first == a[r].first) {
                        mult = true;
                }
        }
        if (inv & 1) {
                if (!mult) {
                        cout << -1 << '\n';
                        return;
                }
                bool ok = false;
                rep(i, n) {
                        if (ok) {
                                break;
                        }
                        rep(j, i) {
                                if (a[i].first == a[j].first) {
                                        swap(a[i], a[j]);
                                        ok = true;
                                        break;
                                }
                        }
                }
        }
        inv = 0;
        rep(r, n) rep(l, r) {
                inv += a[l] > a[r];
        }
        assert(inv % 2 == 0);
        int sorted = -1;
        vector<int> ans;
        while (sorted < n - 3) {
                pair<int, int> mi = make_pair(501, 0);
                int idx = -1;
                for (int i = sorted + 1; i < n; i ++) {
                        if (a[i] < mi) {
                                mi = a[i];
                                idx = i;
                        }
                }
                int cur;
                for (cur = idx; cur - 2 >= sorted + 1; cur -= 2) {
                        swap(a[cur], a[cur - 1]);
                        swap(a[cur - 1], a[cur - 2]);
                        ans.push_back(cur - 2);
                }
                if (cur == sorted + 2) {
                        ans.push_back(cur - 1);
                        ans.push_back(cur - 1);
                        swap(a[cur - 1], a[cur]);
                        swap(a[cur], a[cur + 1]);
                }
                sorted ++;
        }
        while (a[n - 3].first > a[n - 2].first || a[n - 2].first > a[n - 1].first) {
                swap(a[n - 1], a[n - 2]);
                swap(a[n - 2], a[n - 3]);
                ans.push_back(n - 3);
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) cout << ans[i] + 1 << " "; cout << '\n';
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
