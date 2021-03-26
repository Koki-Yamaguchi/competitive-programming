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
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<int> st(n, 1);
        vector<ll> sum(n);
        rep(j, n) {
                sum[j] = st[j];
        }
        rep(i, k) {
                vector<int> nxt(n);
                rep(j, n) {
                        if (j) nxt[j] += st[j - 1];
                        if (j < n - 1) nxt[j] += st[j + 1];
                }
                dump(nxt);
                rep(j, n) {
                        sum[j] += st[j];
                }
                swap(nxt, st);
        }
        dump(st);
        dump(sum);
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
