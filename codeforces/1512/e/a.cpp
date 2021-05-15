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
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        l --, r --;
        int num = r - l + 1;
        int mi = 0, ma = 0;
        for (int i = 0; i < num; i ++) {
                mi += i + 1;
        }
        for (int i = n - 1; i >= n - num; i --) {
                ma += i + 1;
        }
        if (s < mi || ma < s) {
                cout << -1 << '\n';
                return;
        }
        int need = s - mi;
        int inc = n - num;
        if (inc == 0) {
                rep(i, n) {
                        cout << i + 1 << " \n"[i == n - 1];
                }
                return;
        }
        int c = need / inc;
        int rem = need % inc;
        int f = num - c;
        /*
        dump(inc);
        dump(c);
        dump(rem);
        dump(f);
        */
        set<int> use;
        if (rem > 0) {
                f --;
                use.insert(f + 1 + rem);
        }
        for (int i = 1; i <= f; i ++) {
                use.insert(i);
        }
        for (int i = n; i >= n - c + 1; i --) {
                use.insert(i);
        }
        vector<int> left, seg, right;
        for (int i = 1; i <= n; i ++) {
                if (use.count(i)) {
                        seg.push_back(i);
                } else if (left.size() < l) {
                        left.push_back(i);
                } else {
                        right.push_back(i);
                }
        }
        vector<int> ans;
        rep(i, left.size()) {
                ans.push_back(left[i]);
        }
        rep(i, seg.size()) {
                ans.push_back(seg[i]);
        }
        rep(i, right.size()) {
                ans.push_back(right[i]);
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
