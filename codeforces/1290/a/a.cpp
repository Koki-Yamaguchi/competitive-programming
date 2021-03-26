#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p) {
        os << p.first << " " << p.second;
        return os;
}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        k = min(k, m - 1);
        int choose = m - k - 1;
        if (choose == 0) {
                int ma = 0;
                rep(i, m) {
                        ma = max(ma, a[i]);
                }
                for (int i = n - 1; i >= n - m; i --) {
                        ma = max(ma, a[i]);
                }
                cout << ma << '\n';
                return;
        }
        auto func = [](int a, int b) { return min(a, b); };
        const int inf = 1e9;
        segment_tree<decltype(func), int> segtree(n, func, inf);
        rep(i, n) {
                segtree.update(i, a[i]);
        }
        int ans = 0;
        for (int a = 0; a <= k; a ++) {
                int b = k - a;
                /*
                dump(a);
                dump(b);
                dump(choose);
                cerr << "seg = [" << a << ", " << a + choose << ")\n";
                cerr << "seg = [" << n - b - choose << ", " << n - b << ")\n";
                */
                if (a + choose + 1 > n - b - choose - 1) {
                        ans = max(ans, segtree.query(a, n - b));
                } else {
                        ans = max(ans, min(segtree.query(a, a + choose), segtree.query(n - b - choose, n - b)));
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
