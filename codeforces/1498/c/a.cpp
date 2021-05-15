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

const ll MOD = 1e9 + 7;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> left(n, vector<int> (k + 1));
        vector<vector<int>> right(n, vector<int> (k + 1));
        if (n == 1) {
                if (k == 1) {
                        cout << 1 << '\n';
                } else {
                        cout << 2 << '\n';
                }
                return;
        }
        for (int age = 1; age <= k; age ++) {
                if ((k - age) & 1) {
                        for (int i = 0; i < n; i ++) {
                                if (i > 0 && i < n - 1) {
                                        (right[i][age] = right[i - 1][age] + left[i + 1][age - 1]) %= MOD;
                                } else if (i < n - 1) {
                                        (right[i][age] = 1 + left[i + 1][age - 1]) %= MOD;
                                } else if (i > 0) {
                                        (right[i][age] = right[i - 1][age] + (age > 1)) %= MOD;
                                }
                        }
                } else {
                        for (int i = n - 1; i >= 0; i --) {
                                if (i > 0 && i < n - 1) {
                                        (left[i][age] = right[i - 1][age - 1] + left[i + 1][age]) %= MOD;
                                } else if (i < n - 1) {
                                        (left[i][age] = (age > 1) + left[i + 1][age]) %= MOD;
                                } else if (i > 0) {
                                        (left[i][age] = right[i - 1][age - 1] + 1) %= MOD;
                                }
                        }
                }
        }
        cout << left[0][k] << '\n';
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
