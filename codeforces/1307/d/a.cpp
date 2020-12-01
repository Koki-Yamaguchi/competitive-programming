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

//unweighted graph
vector<int> Dijkstra(int start, const vector<vector<int>> &g) {
        int n = (int) g.size();
        vector<int> dist(n, 1 << 30);
        priority_queue<pair<int, int>> que;
        dist[start] = 0;
        que.push({0, start});
        while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int u = p.second;
                for (auto v : g[u]) {
                        if (dist[v] > dist[u] + 1) {
                                dist[v] = dist[u] + 1;
                                que.push({-dist[v], v});
                        }
                }
        }
        return dist;
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

const int inf = 1e9 + 5;

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> p(k);
        rep(i, k) {
                cin >> p[i];
                p[i] --;
        }
        sort(all(p));
        vector<vector<int>> g(n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        int s = 0;
        int t = n - 1;
        auto ds = Dijkstra(s, g);
        auto dt = Dijkstra(t, g);
        vector<pair<int, int>> c;
        rep(i, k) {
                c.emplace_back(ds[p[i]], dt[p[i]]);
        }
        sort(all(c));
        auto func = [](int a, int b) { return max(a, b); };
        segment_tree<decltype(func), int> segtree(k, func, -inf);
        rep(i, k) {
                segtree.update(i, c[i].second);
        }
        int lb = 0, ub = inf;
        while (ub - lb > 1) {
                int x = (lb + ub) / 2;
                bool f = false;
                rep(i, k) {
                        int rs = x - c[i].second;
                        int rt = x - c[i].first;
                        pair<int, int> unko = {rs, -inf};
                        auto pos = lower_bound(all(c), unko) - c.begin();
                        if (pos == k) continue;
                        int ma = max(segtree.query(pos, i), segtree.query(i + 1, k));
                        if (ma >= rt) {
                                f = true;
                                break;
                        }
                }
                if (f) {
                        lb = x;
                } else {
                        ub = x;
                }
        }
        cout << min(lb + 1, ds[t]) << '\n';
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
