#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> ostream& operator << (ostream& os, const set<T> &p) { os << "{"; for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << *it; } os << "}"; return os; }
template<typename T, typename U> ostream& operator << (ostream& os, const map<T, U> &p) { for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << "{" << (*it).first << ": " << (*it).second << "}"; } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

const ll MOD = 998244353;
void solve() {
        int n;
        cin >> n;
        n *= 2;
        vector<int> mif(n + 1, -1);
        for (int i = 2; i <= n; i ++) {
                if (mif[i] == -1) {
                        mif[i] = i;
                        for (int j = i + i; j <= n; j += mif[i]) {
                                mif[j] = i;
                        }
                }
        }
        vector<ll> ans(n + 1);
        ll acc = 0;
        auto get_num = [&](int v) {
                ll res = 1;
                while (v > 1) {
                        int p = mif[v];
                        int c = 0;
                        while (v % p == 0) {
                                v /= p;
                                c ++;
                        }
                        res *= c + 1;
                }
                return res;
        };
        for (int i = 2; i <= n; i += 2) {
                ll num = get_num(i / 2);
                (ans[i] = acc + num) %= MOD;
                (acc += ans[i]) %= MOD;
        }
        cout << ans[n] << '\n';
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
