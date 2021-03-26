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
        vector<pair<pair<int, int>, int>> a(n);
        rep(i, n) {
                cin >> a[i].first.first >> a[i].first.second;
                a[i].second = i;
        }
        sort(all(a));
        vector<int> wmi(n), wmii(n);
        wmi[0] = a[0].first.second;
        wmii[0] = a[0].second;
        rep(i, n) if (i) {
                wmi[i] = min(wmi[i - 1], a[i].first.second);
                if (a[i].first.second < wmi[i - 1]) {
                        wmii[i] = a[i].second;
                } else {
                        wmii[i] = wmii[i - 1];
                }
        }
        vector<int> ans(n, -1);
        rep(i, n) {
                int idx = a[i].second;
                {
                        int v = a[i].first.first;
                        pair<pair<int, int>, int> r = {{v, -1e9}, -1e9};
                        int p = upper_bound(all(a), r) - a.begin();
                        p --;
                        if (p >= 0) {
                                int pos = wmii[p];
                                int x = wmi[p];
                                if (x < a[i].first.second) {
                                        ans[idx] = pos + 1;
                                }
                        }
                }
                {
                        int v = a[i].first.second;
                        pair<pair<int, int>, int> r = {{v, -1e9}, -1e9};
                        int p = upper_bound(all(a), r) - a.begin();
                        p --;
                        if (p >= 0) {
                                int pos = wmii[p];
                                int x = wmi[p];
                                if (x < a[i].first.first) {
                                        ans[idx] = pos + 1;
                                }
                        }
                }
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
