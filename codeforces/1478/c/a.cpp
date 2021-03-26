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
        vector<ll> a(2 * n);
        rep(i, 2 * n) {
                cin >> a[i];
        }
        sort(rall(a));
        vector<ll> b;
        rep(i, 2 * n) {
                if (i & 1) {
                        if (a[i] != a[i - 1]) {
                                cout << "NO\n";
                                return;
                        }
                        b.push_back(a[i]);
                }
        }
        ll acc = 0;
        set<ll> used;
        rep(i, n) {
                if (b[i] < acc) {
                        cout << "NO\n";
                        return;
                }
                b[i] -= acc;
                if (b[i] == 0) {
                        cout << "NO\n";
                        return;
                }
                if (b[i] % 2 != 0) {
                        cout << "NO\n";
                        return;
                }
                ll v = b[i] / 2;
                int c = n - i;
                if (v % c != 0) {
                        cout << "NO\n";
                        return;
                }
                if (used.count(v / c) != 0) {
                        cout << "NO\n";
                        return;
                }
                used.insert(v / c);
                acc += 2 * v / c;
        }
        cout << "YES\n";
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
