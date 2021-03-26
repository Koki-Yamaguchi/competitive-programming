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
        string s, t;
        cin >> s >> t;
        if (s.size() > t.size()) swap(s, t);
        int n = s.size();
        int m = t.size();
        int g = gcd(n, m);
        int l = n * m / g;
        string sss, ttt;
        int nc = l / n;
        int mc = l / m;
        while (nc --) {
                rep(i, n) {
                        sss.push_back(s[i]);
                }
        }
        while (mc --) {
                rep(i, m) {
                        ttt.push_back(t[i]);
                }
        }
        if (sss == ttt) {
                cout << sss << '\n';
        } else {
                cout << "-1\n";
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
