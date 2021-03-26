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
        vector<int> a(n);
        map<int, int> cnt;
        rep(i, n) {
                cin >> a[i];
                cnt[a[i]] ++;
        }
        vector<int> cntv;
        for (auto it : cnt) {
                cntv.push_back(it.second);
        }
        n = cntv.size();
        sort(all(cntv));
        int acc = 0;
        vector<int> bacc(n);
        bacc[n - 1] = cntv[n - 1];
        for (int i = n - 2; i >= 0; i --) {
                bacc[i] = bacc[i + 1] + cntv[i];
        }
        int ans = 1e9;
        rep(i, cntv.size()) {
                ans = min(ans, acc + bacc[i] - (n - i) * cntv[i]);
                acc += cntv[i];
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
