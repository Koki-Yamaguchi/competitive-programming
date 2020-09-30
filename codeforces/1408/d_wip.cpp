#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> a(n), b(m);
        rep(i, n) {
                cin >> a[i].first >> a[i].second;
        }
        rep(i, m) {
                cin >> b[i].first >> b[i].second;
        }

        map<int, int> z, rz;
        vector<int> all;
        rep(i, n) {
                all.push_back(a[i].first);
                all.push_back(a[i].second);
        }
        rep(i, m) {
                all.push_back(b[i].first);
                all.push_back(b[i].second);
        }
        sort(all.begin(), all.end());
        int k = 0;
        for (auto it : all) {
                if (z.count(it) == 0) {
                        z[it] = k;
                        rz[k] = it;
                        k ++;
                }
        }

        rep(i, n) {
                a[i].first = z[a[i].first];
                a[i].second = z[a[i].second];
                cerr << a[i].first << " " << a[i].second << endl;
        }
        rep(i, m) {
                b[i].first = z[b[i].first];
                b[i].second = z[b[i].second];
                cerr << b[i].first << " " << b[i].second << endl;
        }
        cerr << endl;

        sort(b.begin(), b.end(), [&](auto l, auto r) {
                if (l.second != r.second) return l.second > r.second;
                return l.first > r.first;
        });
        vector<pair<int, int>> ceil;
        rep(i, m) {
                if (i == 0 || b[i - 1].second > b[i].second) {
                        ceil.emplace_back(-b[i].first, b[i].second);
                }
        }
        cerr << "ceil" << endl;
        for (auto it : ceil) {
                cerr << it.first << " " << it.second << endl;
        }
        cerr << endl;

        long long ans = 1e9;
        rep(mvx, k) {
                int ma = 0;
                rep(i, n) {
                        int x = -(a[i].first + mvx);
                        pair<int, int> sr = make_pair(x, 1e9 + 10);
                        int idx = upper_bound(ceil.begin(), ceil.end(), sr) - ceil.begin();
                        idx = max(0, idx - 1);
                        ma = max(ma, max(0, rz[a[i].second] - rz[ceil[idx].second] + 1));
                }
                ans = min(ans, (long long) ma + (long long) rz[mvx] - rz);
        }
        cout << ans << '\n';
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
