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

int ask(int l, int r) {
        cout << "? " << l + 1 << " " << r + 1 << endl;
        int s;
        cin >> s;
        return s;
}

void answer(int r) {
        cout << "! " << r + 1 << '\n';
        return;
}

void solve() {
        int n, t;
        cin >> n >> t;
        int k;
        cin >> k;
        int lb = -1, ub = n;
        while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                int sum = ask(0, mid);
                int zn = mid + 1 - sum;
                if (zn <= k - 1) {
                        lb = mid;
                } else {
                        ub = mid;
                }
        }
        answer(lb + 1);
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
