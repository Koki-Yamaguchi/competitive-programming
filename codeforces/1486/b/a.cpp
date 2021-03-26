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

ll calc(vector<int> &p) {
        sort(all(p));
        int n = p.size();
        if (n & 1) {
                return 1ll;
        } else {
                return (ll) (p[n / 2] - p[n / 2 - 1] + 1);
        }
}

void solve() {
        int n;
        cin >> n;
        vector<int> xs, ys;
        rep(i, n) {
                int y, x;
                cin >> y >> x;
                ys.push_back(y);
                xs.push_back(x);
        }
        cout << calc(xs) * calc(ys) << '\n';
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
