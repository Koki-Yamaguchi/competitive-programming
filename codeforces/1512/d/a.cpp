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
        vector<ll> a(n + 2);
        ll s = 0;
        rep(i, n + 2) {
                cin >> a[i];
                s += a[i];
        }
        map<ll, ll> cnt;
        rep(i, n + 2) {
                cnt[a[i]] ++;
        }
        rep(i, n + 2) {
                ll sss = a[i];
                cnt[sss] --;
                ll r = s - 2 * sss;
                if (cnt[r] > 0) {
                        int rj = -1;
                        rep(j, n + 2) {
                                if (a[j] == r && i != j) {
                                        rj = j;
                                        break;
                                }
                        }
                        vector<int> ans;
                        rep(j, n + 2) {
                                if (j != i && j != rj) {
                                        ans.push_back(a[j]);
                                }
                        }
                        cout << ans << '\n';
                        return;
                }
                cnt[sss] ++;
        }
        cout << -1 << '\n';
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
