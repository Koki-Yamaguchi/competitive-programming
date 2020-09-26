#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

void solve() {
        int n, m;
        cin >> n >> m;
        int mx = 1000000;
        vector<vector<int>> in(mx + 1), out(mx + 1);
        long long ans = 1;
        rep(i, n) {
                int y, lx, rx;
                cin >> y >> lx >> rx;
                in[lx].push_back(y);
                out[rx].push_back(y);
                if (lx == 0 && rx == mx) {
                        ans ++;
                }
        }
        vector<pair<int, int>> lines(mx + 1, make_pair(-1, -1));
        rep(i, m) {
                int x, ly, ry;
                cin >> x >> ly >> ry;
                lines[x] = make_pair(ly, ry);
        }
        fenwick_tree<long long> ft(mx + 1);
        ft.add(0, 1);
        ft.add(mx, 1);
        rep(i, mx + 1) {
                for (auto r : in[i]) {
                        ft.add(r, 1);
                }
                if (lines[i].first != -1) {
                        ans += ft.sum(lines[i].first, lines[i].second + 1) - 1;
                }
                for (auto l : out[i]) {
                        ft.add(l, -1);
                }
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
