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

int ask(const vector<int> &vals) {
        int n = vals.size();
        cout << "? ";
        cout << n << " ";
        cout << vals << endl;
        int res;
        cin >> res;
        return res;
}

void answer(const vector<int> &vals) {
        cout << "! ";
        cout << vals << endl;
        string res;
        cin >> res;
        assert(res == "Correct");
}

void solve() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> vals(k);
        rep(i, k) {
                int c;
                cin >> c;
                vals[i].resize(c);
                rep(j, c) {
                        cin >> vals[i][j];
                }
        }
        vector<int> al;
        rep(i, n) {
                al.push_back(i + 1);
        }
        int m = ask(al);
        int lb = 0, ub = k;
        while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                vector<int> vals_a, vals_b;
                rep(i, mid) {
                        rep(j, vals[i].size()) {
                                vals_a.push_back(vals[i][j]);
                        }
                }
                for (int i = mid; i < ub; i ++) {
                        rep(j, vals[i].size()) {
                                vals_b.push_back(vals[i][j]);
                        }
                }
                int res = ask(vals_a);
                if (res != m) {
                        lb = mid;
                } else {
                        ub = mid;
                }
        }
        vector<int> s = vals[lb];
        set<int> ss;
        rep(i, s.size()) {
                ss.insert(s[i]);
        }
        vector<int> sc;
        for (int i = 1; i <= n; i ++) {
                if (ss.count(i) == 0) {
                        sc.push_back(i);
                }
        }
        int r = ask(sc);
        vector<int> ans;
        rep(i, k) {
                if (i != lb) {
                        ans.push_back(m);
                } else {
                        ans.push_back(r);
                }
        }
        answer(ans);
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