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
        int n, w;
        cin >> n >> w;
        vector<int> l(n);
        rep(i, n) {
                cin >> l[i];
        }
        sort(rall(l));
        vector<int> v;
        rep(i, n) {
                if (v.size() == 0) {
                        v.push_back(- l[i]);
                } else {
                        int p = lower_bound(all(v), - (w - l[i])) - v.begin();
                        if (p == v.size()) {
                                v.push_back(- l[i]);
                        } else {
                                v[p] -= l[i];
                        }
                }
        }
        cout << v.size() << '\n';
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
