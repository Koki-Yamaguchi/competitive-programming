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

void solve() {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        map<int, int> prev;
        int fin = -1;
        vector<vector<int>> g(n);
        vector<pair<int, int>> segs;
        rep(i, n) {
                int v = a[i];
                vector<int> ps;
                for (int j = 2; j * j <= v; j ++) {
                        if (v % j == 0) {
                                while (v % j == 0) {
                                        v /= j;
                                }
                                ps.push_back(j);
                        }
                }
                if (v > 1) {
                        ps.push_back(v);
                }
                int mai = -1;
                for (auto p : ps) {
                        if (prev.count(p) > 0) {
                                mai = max(mai, prev[p]);
                        }
                        prev[p] = i;
                }
                if (mai != -1 && mai > fin) {
                        g[mai].push_back(i);
                        cerr << mai << " -> " << i << endl;
                        segs.emplace_back(mai, i);
                }
                fin = max(fin, mai);
        }
        int k = segs.size();
        vector<int> to(k + 1);
        to[k] = k;
        rep(i, segs.size()) {
                auto [l, r] = segs[i];
                pair<int, int> f = make_pair(r, -1e9);
                int pos = lower_bound(all(segs), f) - segs.begin();
                to[i] = pos;
        }
        rep(i, k) {
                dump(to[i]);
        }

        // TODO doubling...

        while (q --) {
                int l, r;
                cin >> l >> r;
                l --, r --;
                pair<int, int> f = make_pair(r, -1e9);
                int pos = lower_bound(all(segs), f) - segs.begin();
                int ans = 0;
                while (to[pos] != k) {
                        ans ++;
                        pos = to[pos];
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
