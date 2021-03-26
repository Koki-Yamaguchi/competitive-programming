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
        int a, b, k;
        cin >> a >> b >> k;
        b --;
        if (k == 0) {
                cout << "Yes\n";
                cout << '1';
                rep(i, b) {
                        cout << '1';
                }
                rep(i, a) {
                        cout << '0';
                }
                cout << '\n';
                cout << '1';
                rep(i, b) {
                        cout << '1';
                }
                rep(i, a) {
                        cout << '0';
                }
                cout << '\n';
                return;
        }
        int n = a + b;
        a *= 2;
        b *= 2;
        if (a < 2 || b < 2) {
                cout << "No\n";
                return;
        }
        if (a + b < 2 * (k + 1)) {
                cout << "No\n";
                return;
        }
        cout << "Yes\n";
        string ansa, ansb;
        ansa.push_back('0');
        ansb.push_back('1');
        a --;
        b --;
        k --;
        while (k --) {
                if (a >= 2) {
                        ansa.push_back('0');
                        ansb.push_back('0');
                        a -= 2;
                } else {
                        ansa.push_back('1');
                        ansb.push_back('1');
                        b -= 2;
                }
        }
        ansa.push_back('1');
        ansb.push_back('0');
        a --;
        b --;
        while (ansa.size() < n) {
                if (a >= 2) {
                        ansa.push_back('0');
                        ansb.push_back('0');
                        a -= 2;
                } else {
                        ansa.push_back('1');
                        ansb.push_back('1');
                        b -= 2;
                }
        }
        reverse(all(ansa));
        reverse(all(ansb));
        cout << '1' << ansa << '\n';
        cout << '1' << ansb << '\n';
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
