#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

//verified CSA_045 C
//区間加算、区間最小値
const long long INF = 1e12;
template<typename Type>
struct LazySegmentTree {
        vector<pair<Type, int>> data;
        vector<Type> lazy;
        int n;
        LazySegmentTree(int x) {
                n = pow(2, ceil(log2(x)));
                data.resize(2 * n - 1, make_pair(INF, -1));
                lazy.resize(2 * n - 1, 0);
        }
        void init(int k, Type p) {
                int idx = k;
                k += n - 1;
                data[k] = make_pair(p, idx);
                while (k > 0) {
                        k = (k - 1) / 2;
                        // data[k] = min(data[k * 2 + 1], data[k * 2 + 2]);
                        auto l = data[k * 2 + 1];
                        auto r = data[k * 2 + 2];
                        if (l.first < r.first || l.second > r.second) {
                                data[k] = l;
                        } else {
                                data[k] = r;
                        }
                }
        }
        void add(int a, int b, Type x) { cerr << "add [" << a << ", " << b << ") += " << x << '\n'; return add(a, b, x, 0, 0, n); }
        void add(int a, int b, Type x, int k, int l, int r) {
                if (r <= a || b <= l) return;
                if (a <= l && r <= b) {
                        lazy[k] += x;
                        return;
                }
                int m = (l + r) / 2;
                add(a, b, x, k * 2 + 1, l, m);
                add(a, b, x, k * 2 + 2, m, r);
                auto ld = data[k * 2 + 1];
                auto ll = lazy[k * 2 + 1];
                auto rd = data[k * 2 + 2];
                auto rl = lazy[k * 2 + 2];
                if (ld.first + ll < rd.first + rl || ld.second > rd.second) {
                        data[k] = make_pair(ld.first + ll, ld.second);
                } else {
                        data[k] = make_pair(rd.first + rl, rd.second);
                }
        }
        pair<Type, int> getmin(int a, int b) { return getmin(a, b, 0, 0, n); }
        pair<Type, int> getmin(int a, int b, int k, int l, int r) {
                if (r <= a || b <= l) return make_pair(INF, -1);
                if (a <= l && r <= b) return make_pair(data[k].first + lazy[k], data[k].second);
                int m = (l + r) / 2;
                auto left = getmin(a, b, k * 2 + 1, l, m);
                auto right = getmin(a, b, k * 2 + 2, m, r);
                if (left.first < right.first || left.second > right.second) {
                        return make_pair(left.first + lazy[k], left.second);
                } else {
                        return make_pair(right.first + lazy[k], right.second);
                }
        }
};

void solve() {
        int h, w;
        cin >> h >> w;
        LazySegmentTree<long long> st(w);
        rep(i, w) {
                st.init(i, 0);
        }
        vector<long long> ans(h);
        rep(i, h) {
                int l, r;
                cin >> l >> r;
                l --;
                pair<long long, int> mi = st.getmin(l, r);
                cerr << "mi = " << mi.first << " " << mi.second << endl;
                st.add(l, r, INF);
                st.add(0, l, 1);
                if (r < w) {
                        st.add(r, w, 1);
                        long long val = mi.first + r - mi.second + 1;
                        cerr << "val = " << val << endl;
                        long long cur = st.getmin(r, r + 1).first;
                        cerr << "cur = " << cur << endl;
                rep(j, w) cerr << st.getmin(j, j + 1).first << " "; cerr << endl;
                        if (cur > val) {
                                st.add(r, r + 1, val - cur);
                        }
                }
                cerr << "current data" << endl;
                rep(j, w) cerr << st.getmin(j, j + 1).first << " "; cerr << endl;
                ans[i] = st.getmin(0, w).first;
        }
        rep(i, h) {
                cout << ans[i] << '\n';
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
