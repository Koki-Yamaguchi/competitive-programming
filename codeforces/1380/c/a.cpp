#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

// verified at 'https://judge.yosupo.jp/problem/point_add_range_sum'
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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> dp(n + 1);
        auto f = [&](int a, int b) { return max(a, b); };
        segment_tree<decltype(f), int> st(n + 1, f, 0);
        rep(i, n) {
                int cnt = (x + (a[i] - 1)) / a[i];
                // cerr << "cn = " << cnt << endl;
                if (i + 1 + cnt - 1 <= n) {
                        dp[i + 1 + cnt - 1] = max(dp[i + 1 + cnt - 1], st.query(0, i + 1) + 1);
                        st.update(i + 1 + cnt - 1, dp[i + 1 + cnt - 1]);
                }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
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
