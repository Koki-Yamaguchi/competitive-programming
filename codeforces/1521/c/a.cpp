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

int ask(int t, int i, int j, int x) {
        cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << x << endl;
        int res;
        cin >> res;
        return res;
}

void answer(const vector<int> &ans) {
        cout << "! ";
        rep(i, ans.size()) {
                cout << ans[i];
                if (i + 1 < ans.size()) {
                        cout << " ";
                } else {
                        cout << endl;
                }
        }
}

void solve() {
        int n;
        cin >> n;
        int nidx = -1;
        for (int i = 0; i + 1 < n; i += 2) {
                int j = i + 1;
                int res = ask(1, i, j, n - 1);
                if (res == n) {
                        nidx = j;
                        break;
                } else if (res == n - 1) {
                        int res = ask(2, i, j, n - 1);
                        if (res == n) {
                                nidx = i;
                                break;
                        }
                }
        }
        if (nidx == -1) { // last one must be n
                int res = ask(2, n - 1, 0, n - 1);
                assert(res == n);
                nidx = n - 1;
        }
        vector<int> ans(n);
        ans[nidx] = n;
        rep(i, n) if (i != nidx) {
                int res = ask(2, i, nidx, 1);
                ans[i] = res;
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
