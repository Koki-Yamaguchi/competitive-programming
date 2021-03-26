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
        if (n <= 4) {
                if (n == 3) {
                        cout << "2\n3 2\n3 2\n";
                        return;
                } else if (n == 4) {
                        cout << "3\n3 4\n4 2\n4 2\n";
                        return;
                }
        }
        if (n <= 60) {
                vector<pair<int, int>> ans;
                for (int i = 3; i <= n - 1; i ++) {
                        if (i != 4) {
                                ans.emplace_back(i, n);
                        }
                }
                int val = n;
                while (val > 1) {
                        ans.emplace_back(n, 4);
                        val = (val + 3) / 4;
                }
                ans.emplace_back(4, 2);
                ans.emplace_back(4, 2);
                cout << ans.size() << '\n';
                assert(ans.size() <= n + 5);
                rep(i, ans.size()) {
                        cout << ans[i] << '\n';
                }
                return;
        }
        vector<pair<int, int>> ans;
        for (int i = 3; i <= n - 1; i ++) {
                if (i != 4 && i != 60) {
                        ans.emplace_back(i, n);
                }
        }
        int val = n;
        while (val > 1) {
                ans.emplace_back(n, 60);
                val = (val + 59) / 60;
        }
        val = 60;
        while (val > 1) {
                ans.emplace_back(60, 4);
                val = (val + 3) / 4;
        }
        ans.emplace_back(4, 2);
        ans.emplace_back(4, 2);
        assert(ans.size() <= n + 5);
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i] << '\n';
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
