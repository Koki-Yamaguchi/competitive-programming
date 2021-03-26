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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        ll sum = 0;
        rep(i, n) {
                cin >> a[i];
                sum += a[i];
        }
        rep(i, n) {
                cin >> b[i];
        }
        if (sum < m) {
                cout << "-1\n";
                return;
        }
        vector<int> c1, c2;
        rep(i, n) {
                if (b[i] == 1) {
                        c1.push_back(a[i]);
                } else if (b[i] == 2) {
                        c2.push_back(a[i]);
                } else {
                        assert(false);
                }
        }
        sort(rall(c1));
        sort(rall(c2));
        vector<ll> acc(c2.size() + 1);
        rep(i, c2.size()) {
                acc[i + 1] = acc[i] + c2[i];
        }
        ll u1 = 0;
        int ans = 1e9;
        for (int i = 0; i <= c1.size(); i ++) { if (i) {
                        u1 += c1[i - 1];
                }
                ll need = m - u1;
                if (need <= 0) {
                        ans = min(ans, i);
                        continue;
                }
                int pos = lower_bound(all(acc), need) - acc.begin();
                if (pos == acc.size()) {
                        continue;
                }
                int res = i + 2 * pos;
                ans = min(ans, res);
        }
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
