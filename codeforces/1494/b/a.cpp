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
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        rep(s, 1 << 4) {
                int cu = 0, cr = 0, cd = 0, cl = 0;
                rep(i, 4) {
                        if ((s >> i) & 1) {
                                if (i == 0) {
                                        cl ++;
                                        cu ++;
                                } else if (i == 1) {
                                        cu ++;
                                        cr ++;
                                } else if (i == 2) {
                                        cr ++;
                                        cd ++;
                                } else {
                                        cd ++;
                                        cl ++;
                                }
                        }
                }
                if (u - cu < 0 || r - cr < 0 || d - cd < 0 || l - cl < 0) {
                        continue;
                }
                if (u - cu <= n - 2 && r - cr <= n - 2 && d - cd <= n - 2 && l - cl <= n - 2) {
                        cout << "YES\n";
                        return;
                }
        }
        cout << "NO\n";
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
