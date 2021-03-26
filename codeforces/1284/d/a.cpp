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

struct area {
        int xl;
        int xr;
        int yl;
        int yr;
};

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

bool slv(const vector<pair<int, int>> &tmpx, const vector<pair<int, int>> &tmpy) {
        vector<pair<int, int>> x = tmpx, y = tmpy;
        int n = x.size();
        vector<area> a(n);
        rep(i, n) {
                area p;
                p.xl = x[i].first;
                p.xr = x[i].second;
                p.yl = y[i].first;
                p.yr = y[i].second;
                a[i] = p;
        }
        sort(all(a), [&](auto lhs, auto rhs) {
                if (lhs.xl == rhs.xl) {
                        return lhs.xr < rhs.xr;
                }
                return lhs.xl < rhs.xl;
        });
        sort(all(y));
        /*
        map<pair<int, int>, int> idx;
        rep(i, n) {
                idx[y[i]] = i;
        }
        */
        auto func = [](int u, int v) { return max(u, v); };
        segment_tree<decltype(func), int> segtree(n, func, -1e9 - 10);
        vector<pair<int, int>> cury;
        bool ok = false;
        int nxti = 0;
        rep(i, n) {
                int xl = a[i].xl;
                int prvi = nxti;
                while (a[nxti].xr < xl) {
                        nxti ++;
                }
                // [prvi, nxti)
                if (prvi == nxti) {
                        continue;
                }
                for (int j = prvi; j < nxti; j ++) {
                        pair<int, int> r = {a[j].yl, a[j].yr};
                        cury.insert(upper_bound(all(cury), r), r);
                        // int id = idx[r];
                        int id = lower_bound(all(y), r) - y.begin();
                        segtree.update(id, a[j].yr);
                }
                int yl = a[i].yl;
                int yr = a[i].yr;
                pair<int, int> r = {yr, -1e9 - 10};
                int pos = upper_bound(all(cury), r) - cury.begin();
                if (pos == 0) continue;
                auto v = cury[pos - 1];
                // int id = idx[v];
                int id = lower_bound(all(y), v) - y.begin();
                int ma = segtree.query(0, id + 1);
                if (ma >= yl) {
                        ok = true;
                        break;
                }
        }
        return ok;
}

void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> x(n), y(n);
        rep(i, n) {
                cin >> x[i].first >> x[i].second >> y[i].first >> y[i].second;
        }
        bool found = slv(x, y);
        found = found || slv(y, x);
        cout << (found ? "NO\n" : "YES\n");
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
