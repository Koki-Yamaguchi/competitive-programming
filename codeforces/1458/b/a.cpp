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
        int n; cin >> n;
        vector<pair<int, int>> cl(n);
        int capsum = 0;
        int lsum = 0;
        rep(i, n) {
                cin >> cl[i].first >> cl[i].second;
                capsum += cl[i].first;
                lsum += cl[i].second;
        }
        const int mi = -1e8;
        vector<vector<int>> cur(n + 1, vector<int> (capsum + 1, mi));
        cur[0][0] = 0;
        rep(i, n) {
                auto nxt = cur;
                int cap = cl[i].first;
                int l = cl[i].second;
                rep(j, n + 1) {
                        rep(c, capsum + 1) {
                                if (cur[j][c] != mi) {
                                        if (j + 1 < n + 1 && c + cap < capsum + 1) {
                                                chmax(nxt[j + 1][c + cap], cur[j][c] + l);
                                        }
                                }
                        }
                }
                swap(cur, nxt);
        }
        vector<double> ans(n);
        rep(i, n) {
                rep(c, capsum + 1) {
                        int sl = cur[i + 1][c];
                        ans[i] = max(ans[i], min((double) c, (double) sl + (double) (lsum - sl) / 2.0));
                }
        }
        cout << fixed << setprecision(10) << ans << '\n';
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
