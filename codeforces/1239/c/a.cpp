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
        int n;
        ll p;
        cin >> n >> p;
        vector<pair<ll, int>> a(n);
        rep(i, n) {
                cin >> a[i].first;
                a[i].second = i;
        }
        sort(all(a));
        const int inf = 1e9 + 5;
        auto f = [](pair<int, int> a, pair<int, int> b) { return min(a, b); };
        using seg_t = segment_tree<decltype(f), pair<int, int>>;
        seg_t segtree(n, f, {inf, inf});
        rep(i, n) {
                segtree.update(i, {a[i].second, i});
        }
        vector<ll> ans(n);
        ll cur = 0;
        int curidx = 0;
        int cnt = 0;
        while (true) {
                if (curidx != n && a[curidx].first > cur) {
                        cur = a[curidx].first;
                }
                pair<ll, int> r = make_pair(cur, inf);
                int pos = upper_bound(all(a), r) - a.begin();
                pair<int, int> res = segtree.query(0, pos);
                int idx = res.first;
                int idxidx = res.second;
                assert(idx != inf && idxidx != inf);
                cur += p;
                ans[idx] = cur;
                segtree.update(idxidx, {inf, inf});
                curidx = pos;
                cnt ++;
                if (cnt == n) {
                        break;
                }
        }
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