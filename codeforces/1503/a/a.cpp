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

bool check(const string &s) {
        int sum = 0;
        int n = s.size();
        rep(i, n) {
                if (s[i] == '(') {
                        sum ++;
                } else {
                        sum --;
                }
                if (sum < 0) {
                        return false;
                }
        }
        return sum == 0;
}

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c = 0;
        rep(i, n) {
                if (s[i] == '1') {
                        c ++;
                }
        }
        if (c & 1) {
                cout << "NO\n";
                return;
        }
        c /= 2;
        string ansa(n, '*');
        string ansb(n, '*');
        rep(i, n) {
                if (s[i] == '1') {
                        if (c > 0) {
                                ansa[i] = '(';
                                ansb[i] = '(';
                                c --;
                        } else {
                                ansa[i] = ')';
                                ansb[i] = ')';
                        }
                }
        }
        bool f = false;
        rep(i, n) {
                if (s[i] == '0') {
                        if (f) {
                                ansa[i] = ')';
                                ansb[i] = '(';
                        } else {
                                ansa[i] = '(';
                                ansb[i] = ')';
                        }
                        f = not f;
                }
        }
        if (check(ansa) && check(ansb)) {
                cout << "YES\n";
                cout << ansa << '\n' << ansb << '\n';
        } else {
                cout << "NO\n";
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
