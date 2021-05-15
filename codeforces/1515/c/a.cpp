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
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<ll, int>> h(n);
        rep(i, n) {
                cin >> h[i].first;
                h[i].second = i;
        }
        sort(rall(h));
        priority_queue<pair<ll, int>> que;
        rep(i, m) {
                que.push({- 0, i});
        }
        vector<ll> ans(n);
        rep(i, n) {
                auto [cur, idx] = que.top(); que.pop();
                ans[h[i].second] = idx + 1;
                que.push({cur - h[i].first, idx});
        }
        ll mi = 1e15;
        ll ma = 0;
        while (not que.empty()) {
                auto [cur, _] = que.top(); que.pop();
                cur *= -1;
                mi = min(mi, cur);
                ma = max(ma, cur);
        }
        if (ma - mi <= x) {
                cout << "YES\n";
                cout << ans << '\n';
        } else {
                cout << "NO\n";
        }
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
