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
        string s;
        cin >> s;
        vector<int> pos;
        int c = 0;
        int rm = -1, lm = 1e9;
        rep(i, n) {
                if (s[i] == '*') {
                        pos.push_back(i);
                        c ++;
                        rm = max(rm, i);
                        lm = min(lm, i);
                }
        }
        sort(all(pos));
        if (c == 0) {
                cout << 0 << '\n';
                return;
        }
        int m = pos[c / 2];
        ll ans = 0;
        int emp = 0;
        for (int i = m + 1; i <= rm; i ++) {
                if (s[i] == '.') {
                        emp ++;
                } else {
                        ans += emp;
                }
        }
        emp = 0;
        for (int i = m - 1; i >= lm; i --) {
                if (s[i] == '.') {
                        emp ++;
                } else {
                        ans += emp;
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
