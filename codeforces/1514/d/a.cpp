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
                a[i] --;
        }
        vector<pair<pair<int, int>, int>> qs;
        rep(i, q) {
                int l, r;
                cin >> l >> r;
                l --, r --;
                qs.push_back(make_pair(make_pair(l, r), i));
        }
        int b = sqrt(q);
        sort(all(qs), [&](auto u, auto v) {
                if (u.first.first / b != v.first.first / b) {
                        return u.first.first / b < v.first.first / b;
                }
                int p = u.first.first / b;
                if (p % 2 == 0) {
                        return u.first.second < v.first.second;
                } else {
                        return u.first.second > v.first.second;
                }
        });
        vector<int> cnt(n);
        int cl = 0, cr = 0;
        int curma = -1;
        rep(i, q) {
                int idx = qs[i].second;
                auto [l, r] = qs[i].first;
                int len = r - l + 1;
                int okma = (len + 1) / 2;
                while (cl < l) {
                        cl ++;
                        cnt[a[cl - 1]] --;
                        if (cnt[a[cl - 1]] == okma) {
                                curma = -1;
                        }
                }
                while (cl > l) {
                        cl --;
                        cnt[a[cl]] ++;
                }
                while (cr < r) {
                        cr ++;
                        cnt[a[cr]] ++;
                }
                while (cr > r) {
                        cr --;
                        cnt[a[cr + 1]] --;
                }
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
