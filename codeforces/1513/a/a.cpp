#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> ostream& operator << (ostream& os, const set<T> &p) { os << "{"; for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << *it; } os << "}"; return os; }
template<typename T, typename U> ostream& operator << (ostream& os, const map<T, U> &p) { for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << "{" << (*it).first << ": " << (*it).second << "}"; } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n, k;
        cin >> n >> k;
        int ma = (n - 1) / 2;
        if (ma < k) {
                cout << "-1\n";
                return;
        }
        int cur = n;
        int c = 0;
        vector<int> ans(n, -1);
        for (int i = 1; i < n && c < k; i += 2) {
                ans[i] = cur --;
                c ++;
        }
        for (int i = 0; i < n; i ++) {
                if (ans[i] == -1) {
                        ans[i] = cur --;
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
