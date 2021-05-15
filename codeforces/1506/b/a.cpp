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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> nxt(n, -1);
        for (int i = n - 1; i >= 0; i --) {
                if (s[i] == '*') {
                        nxt[i] = i;
                } else if (i != n - 1) {
                        nxt[i] = nxt[i + 1];
                }
        }
        int c = 1e9;
        int ans = 0;
        rep(i, n) {
                c ++;
                if (s[i] == '*') {
                        int d = i + k - c;
                        if (i == n - 1 || nxt[i + 1] == -1 || nxt[i + 1] > d) {
                                ans ++;
                                c = 0;
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
