#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define bll(a) (a).begin(), (a).end()
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
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        const int sma = 5000000;
        vector<vector<pair<int, int>>> s(sma + 1);
        rep(i, n) {
                for (int j = i + 1; j < n; j ++) {
                        int sm = a[i] + a[j];
                        if (s[sm].size() == 0 || n < 3000 || (s[sm].back().first != i && s[sm].back().second != j)) {
                                s[sm].emplace_back(i, j);
                                rep(p, s[sm].size()) {
                                        for (int q = p + 1; q < s[sm].size(); q ++) {
                                                int x = s[sm][p].first;
                                                int y = s[sm][p].second;
                                                int z = s[sm][q].first;
                                                int w = s[sm][q].second;
                                                if (x != z && x != w && y != z && y != w) {
                                                        cout << "YES\n";
                                                        cout << x + 1 << " " << y + 1 << " " << z + 1 << " " << w + 1 << '\n';
                                                        return;
                                                }
                                        }
                                }
                        }
                }
        }
        cout << "NO\n";
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
