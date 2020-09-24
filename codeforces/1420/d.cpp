#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

const int MOD = 998244353;

const int N = 1000001;
long long fact[N];
long long invfact[N];
long long inv[N];
void init() {
        fact[0] = fact[1] = 1;
        for (int i = 2; i < N; i ++) fact[i] = fact[i - 1] * i % MOD;
        inv[1] = 1;
        for (int i = 2; i < N; i ++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        invfact[0] = invfact[1] = 1;
        for (int i = 2; i < N; i ++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}
long long C(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        return fact[n] * invfact[n - r] % MOD * invfact[r] % MOD;
}

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
        init();
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> seg(n);
        rep(i, n) {
                cin >> seg[i].first >> seg[i].second;
        }
        vector<int> all;
        rep(i, n) {
                all.push_back(seg[i].first);
                all.push_back(seg[i].second);
        }
        sort(all.begin(), all.end());
        map<int, int> z;
        int cur = 1;
        rep(i, all.size()) {
                if (z.count(all[i]) == 0) {
                        z[all[i]] = cur ++;
                }
        }
        rep(i, n) {
                seg[i] = make_pair(z[seg[i].first], z[seg[i].second]);
        }
        auto f = [&](long long a, long long b) { return a + b; };
        long long idt = 0;
        segment_tree<decltype(f), long long> st(2 * n + 10, f, idt);
        sort(seg.begin(), seg.end());
        long long ans = 0;
        rep(i, n) {
                int l = seg[i].first;
                int r = seg[i].second;
                long long s = st.query(l, 2 * n + 10);
                if (s >= k - 1) {
                        (ans += C(s, k - 1)) %= MOD;
                }
                st.update(r, st.query(r, r + 1) + 1);
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
