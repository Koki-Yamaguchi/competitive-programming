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

class min_factor_table {
public:
        min_factor_table(int maxn) : maxn(maxn), min_factors(maxn + 1, -1) {
                min_factors[0] = 0;
                min_factors[1] = 1;
                for (int i = 2; i <= maxn; i ++) {
                        if (min_factors[i] == -1) {
                                min_factors[i] = i;
                                for (int j = i + i; j <= maxn; j += i) {
                                        if (min_factors[j] == -1) {
                                                min_factors[j] = i;
                                        }
                                }
                        }
                }
        }
        vector<int> get_min_factors() {
                return min_factors;
        }
        vector<pair<int, int>> factorize(int n) {
                assert(1 < n && n <= maxn);
                vector<pair<int, int>> res;
                while (n > 1) {
                        int p = min_factors[n];
                        int c = 0;
                        while (n % p == 0) {
                                n /= p;
                                c ++;
                        }
                        res.emplace_back(p, c);
                }
                return res;
        }
private:
        int maxn;
        vector<int> min_factors;
};

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

const long long MOD = 1e9 + 7;

long long ModPow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % MOD;
                x = x * x % MOD;
                n >>= 1;
        }
        return res;
}

void solve() {
        min_factor_table mft(200000);
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<map<int, int>> last(n);
        rep(i, n) {
                if (a[i] > 1) {
                        auto fs = mft.factorize(a[i]);
                        for (auto it : fs) {
                                last[i][it.first] += it.second;
                        }
                }
        }
        vector<int> idx(q), x(q);
        rep(i, q) {
                cin >> idx[i] >> x[i];
                idx[i] --;
                if (x[i] > 1) {
                        auto fs = mft.factorize(x[i]);
                        for (auto it : fs) {
                                last[idx[i]][it.first] += it.second;
                        }
                }
        }
        vector<int> pc(200001);
        vector<bool> can(200001);
        rep(i, n) {
                for (auto it : last[i]) {
                        pc[it.first] ++;
                }
        }
        rep(i, 200001) {
                if (pc[i] == n) {
                        can[i] = true;
                }
        }
        auto f = [&](map<int, int> mpa, map<int, int> mpb) {
                map<int, int> res;
                if (mpa.count(-1) != 0 && mpb.count(-1) != 0) {
                        res[-1] = 1;
                        return res;
                } else if (mpa.count(-1) != 0) {
                        return mpb;
                } else if (mpb.count(-1) != 0) {
                        return mpa;
                }
                for (auto it : mpa) {
                        if (mpb.count(it.first) == 0) {
                                continue;
                        }
                        res[it.first] = min(mpb[it.first], it.second);
                }
                return res;
        };
        map<int, int> idt;
        idt[-1] = 1;
        segment_tree<decltype(f), map<int, int>> segtree(n, f, idt);
        rep(i, n) {
                map<int, int> r; 
                if (a[i] > 1) {
                        auto fs = mft.factorize(a[i]);
                        for (auto it : fs) {
                                if (not can[it.first]) {
                                        continue;
                                }
                                r[it.first] = it.second;
                        }
                }
                segtree.update(i, r);
        }
        rep(i, q) {
                auto mp = segtree.query(idx[i], idx[i] + 1);
                if (x[i] > 1) {
                        auto fs = mft.factorize(x[i]);
                        for (auto it : fs) {
                                if (not can[it.first]) {
                                        continue;
                                }
                                mp[it.first] += it.second;
                        }
                }
                segtree.update(idx[i], mp);
                auto res = segtree.query(0, n);
                ll ans = 1;
                for (auto it : res) {
                        (ans *= ModPow(it.first, it.second)) %= MOD;
                }
                cout << ans << '\n';
        }
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
