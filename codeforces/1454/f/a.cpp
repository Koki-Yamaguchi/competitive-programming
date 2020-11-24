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
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        auto f = [](int a, int b) { return min(a, b); };
        segment_tree<decltype(f), int> segtree(n, f, 1e9 + 10);
        rep(i, n) {
                segtree.update(i, a[i]);
        }
        vector<int> ma(n), marev(n);
        ma[0] = a[0];
        rep(i, n) if (i) {
                ma[i] = max(a[i], ma[i - 1]);
        }
        marev[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i --) {
                marev[i] = max(a[i], marev[i + 1]);
        }
        for (int r = n - 1; r >= 2; r --) {
                int v = marev[r];
                int lb = lower_bound(all(ma), v) - ma.begin();
                int ub = upper_bound(all(ma), v) - ma.begin();
                ub --;

                if (lb < n && ub >= 0) {
                        if (lb > r - 2) {
                                continue;
                        }
                        if (ma[lb] != v) {
                                continue;
                        }
                        assert(ma[lb] == v);
                        assert(ma[ub] == v);
                        int l0 = min(ub, r - 2);
                        assert(ma[l0] == v);
                        if (segtree.query(l0 + 1, r) == v) {
                                cout << "YES\n";
                                cout << l0 + 1 << " " << r - l0 - 1 << " " << n - r << '\n';
                                return;
                        }
                        int l1 = min(ub - 1, r - 2);
                        if (l1 >= 0 && ma[l1] == v) {
                                if (segtree.query(l1 + 1, r) == v) {
                                        cout << "YES\n";
                                        cout << l1 + 1 << " " << r - l1 - 1 << " " << n - r << '\n';
                                        return;
                                }
                        }
                }
        }
        cout << "NO\n";
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
