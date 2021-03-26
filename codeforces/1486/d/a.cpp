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

bool check(const vector<int> &a, int k, int x) {
        int n = a.size();
        vector<int> b(n);
        rep(i, n) {
                if (a[i] >= x) {
                        b[i] = 1;
                } else {
                        b[i] = -1;
                }
        }
        vector<int> acc(n + 1);
        rep(i, n) {
                acc[i + 1] = acc[i] + b[i];
        }
        vector<int> accmi(n + 1);
        accmi[0] = acc[0];
        rep(i, n + 1) if (i) {
                accmi[i] = min(accmi[i - 1], acc[i]);
        }
        rep(r, n + 1) {
                int p = r - k;
                if (p < 0) {
                        continue;
                }
                if (acc[r] > accmi[p]) {
                        return true;
                }
        }
        return false;
}

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        int lb = 0, ub = n + 1;
        while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                if (check(a, k, mid)) {
                        lb = mid;
                } else {
                        ub = mid;
                }
        }
        cout << lb << '\n';
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
