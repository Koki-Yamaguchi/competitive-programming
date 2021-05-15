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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> left(l), right(r);
        rep(i, l) {
                cin >> left[i];
                left[i] --;
        }
        rep(i, r) {
                cin >> right[i];
                right[i] --;
        }
        if (l > r) {
                swap(l, r);
                swap(left, right);
        }
        assert((r - l) % 2 == 0);
        int mv = (r - l) / 2;
        map<int, int> cntl, cntr;
        rep(i, l) {
                cntl[left[i]] ++;
        }
        rep(i, r) {
                cntr[right[i]] ++;
        }
        vector<int> d(n);
        rep(i, n) {
                d[i] = cntr[i] - cntl[i];
        }
        vector<int> col(n);
        rep(i, n) {
                col[i] = i;
        }
        sort(all(col), [&](auto a, auto b) {
                return d[a] > d[b];
        });
        vector<pair<int, int>> mvs;
        int cur = mv;
        rep(i, n) {
                if (cur == 0) {
                        break;
                }
                int mvv = min(cur, d[col[i]] / 2);
                cur -= mvv;
                mvs.emplace_back(col[i], mvv);
        }
        rep(i, n) {
                if (cur == 0) {
                        break;
                }
                int mvv = min(cur, (d[col[i]] + 1) / 2 - d[col[i]] / 2);
                d[col[i]] = 0;
                cur -= mvv;
                mvs.emplace_back(col[i], mvv);
        }
        assert(cur == 0);
        for (auto it : mvs) {
                cntl[it.first] += it.second;
                assert(cntr[it.first] >= it.second);
                cntr[it.first] -= it.second;
        }
        int ans = 0;
        rep(i, n) {
                ans += abs(cntr[i] - cntl[i]);
        }
        cout << mv + ans / 2 << '\n';
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
