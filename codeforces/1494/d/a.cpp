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
        int n;
        cin >> n;
        vector<tuple<int, int, int>> v;
        vector<int> ans(n);
        rep(i, n) {
                rep(j, n) {
                        if (i == j) {
                                cin >> ans[i];
                        } else {
                                int a;
                                cin >> a;
                                if (i < j) {
                                        v.emplace_back(a, i, j);
                                }
                        }
                }
        }
        sort(all(v));
        int sz = v.size();
        int k = n;
        vector<int> par(n);
        rep(i, n) { par[i] = i; }
        auto find = [&](auto self, int x) -> int {
                if (par[x] == x) {
                        return x;
                }
                return par[x] = self(self, par[x]);
        };
        vector<pair<int, int>> es;
        int i = 0;
        while (i < sz) {
                int val = get<0>(v[i]);
                int j = i;
                while (j < sz && val == get<0>(v[j])) {
                        j ++;
                }
                // [i, j)
                par.push_back(k); // par[k] = k;
                ans.push_back(val);
                for (int idx = i; idx < j; idx ++) {
                        int x = get<1>(v[idx]);
                        int y = get<2>(v[idx]);
                        int px = find(find, x);
                        int py = find(find, y);
                        if (px != k) {
                                es.emplace_back(px, k);
                                par[px] = k;
                        }
                        if (px != py && py != k) {
                                es.emplace_back(py, k);
                                par[py] = k;
                        }
                }
                k ++;
                i = j;
        }
        cout << k << '\n';
        cout << ans << '\n';
        cout << find(find, 0) + 1 << '\n';
        assert(k - 1 == es.size());
        rep(i, k - 1) {
                cout << es[i].first + 1 << " " << es[i].second + 1 << '\n';
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
