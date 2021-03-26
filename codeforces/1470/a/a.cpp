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
        int n, m;
        cin >> n >> m;
        vector<int> idxma(n);
        rep(i, n) {
                cin >> idxma[i];
                idxma[i] --;
        }
        vector<int> cost(m);
        rep(i, m) {
                cin >> cost[i];
        }
        auto f = [](pair<ll, int> a, pair<ll, int> b) { return min(a, b); };
        const pair<ll, int> inf = make_pair(1e12, -1);
        segment_tree<decltype(f), pair<ll, int>> segtree(m, f, inf);
        rep(i, m) {
                segtree.update(i, make_pair(cost[i], i));
        }
        sort(rall(idxma));
        ll ans = 0;
        rep(i, n) {
                pair<ll, int> c = segtree.query(0, idxma[i] + 1);
                if (c.first == inf.first || c.second == idxma[i]) {
                        ans += cost[idxma[i]];
                } else {
                        ans += c.first;
                        segtree.update(c.second, inf);
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
