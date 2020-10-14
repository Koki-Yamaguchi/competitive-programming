#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

template<typename F, typename T>
struct segment_tree {
        F merge;
        T identity;
        vector<T> data;
        int n;
        segment_tree(int len, F _merge, T _identity) : merge(_merge), identity(_identity) {
                n = pow(2, ceil(log2(len)));
                data.resize(2 * n - 1, identity); 
        }
        // update k-th value to p
        void update(int k, T p) {
                k += n - 1;
                data[k] = p;
                while (k > 0) {
                        k = (k - 1) / 2;
                        data[k] = merge(data[k * 2 + 1], data[k * 2 + 2]);
                }
        }
        // [l, r)
        T query(int l, int r) { return query(l, r, 0, 0, n); }
        T query(int a, int b, int k, int l, int r) {
                if (r <= a || b <= l) return identity;
                if (a <= l && r <= b) return data[k];
                int m = (l + r) / 2;
                return merge(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
        }
};

void solve() {
        int r, n;
        cin >> r >> n;
        vector<int> t, x, y;
        t.push_back(0);
        x.push_back(0);
        y.push_back(0);
        rep(i, n) {
                int tt, xx, yy;
                cin >> tt >> xx >> yy;
                xx --, yy --;
                t.push_back(tt);
                x.push_back(xx);
                y.push_back(yy);
        }
        vector<ll> dp(n + 1, -1e16);
        auto f = [](int a, int b) { return max(a, b); };
        segment_tree<decltype(f), long long> segtree(n + 1, f, -1e16);
        dp[0] = 0;
        segtree.update(0, 0);
        rep(i, n) {
                int border = max(0, i - 1006);
                for (int j = i; j >= border; j --) {
                        int dd = abs(x[j] - x[i + 1]) + abs(y[j] - y[i + 1]);
                        int dt = abs(t[j] - t[i + 1]);
                        if (dd <= dt) {
                                dp[i + 1] = max(dp[i + 1], dp[j] + 1);
                        }
                }
                if (border > 0) {
                        dp[i + 1] = max(dp[i + 1], segtree.query(0, border) + 1);
                }
                segtree.update(i + 1, dp[i + 1]);
        }
        cout << *max_element(all(dp)) << '\n';
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
