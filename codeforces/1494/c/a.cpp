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

int calc(vector<ll> &a, vector<ll> &b) {
        sort(all(a));
        sort(all(b));
        int n = a.size();
        int m = b.size();
        if (n == 0 || m == 0) {
                return 0;
        }
        set<ll> as;
        rep(i, n) {
                as.insert(a[i]);
        }
        vector<int> acc(m);
        acc[m - 1] = (as.count(b[m - 1]) > 0);
        for (int i = m - 2; i >= 0; i --) {
                acc[i] = acc[i + 1] + (as.count(b[i]) > 0);
        }
        int res = acc[0];
        rep(i, m) {
                if (as.count(b[i]) == 0) {
                        int p = lower_bound(all(a), b[i]) - a.begin();
                        int l = b[i] - p + 1; // boxes on [l, b[i]]
                        assert(l > 0);
                        int q = lower_bound(all(b), l) - b.begin();
                        int cnt = i - q + 1;
                        int r = cnt + (i < m - 1 ? acc[i + 1] : 0);
                        res = max(res, r);
                }
        }
        return res;
}

void solve() {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, m) {
                cin >> b[i];
        }
        vector<ll> a0, a1, b0, b1;
        rep(i, n) {
                if (a[i] < 0) {
                        a0.push_back(-a[i]);
                } else {
                        a1.push_back(a[i]);
                }
        }
        rep(i, m) {
                if (b[i] < 0) {
                        b0.push_back(-b[i]);
                } else {
                        b1.push_back(b[i]);
                }
        }
        int ans = calc(a0, b0) + calc(a1, b1);
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
