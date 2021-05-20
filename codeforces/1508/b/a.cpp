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

void solve(const vector<ll> &dpf, const vector<ll> &dpb) {
        int n;
        ll k;
        cin >> n >> k;
        if (dpf[n] + dpb[n] < k) {
                cout << -1 << '\n';
                return;
        }
        vector<ll> acc(n + 1);
        acc[1] = dpf[1] + dpb[1];
        const ll inf = 1e18 + 10;
        rep(i, n + 1) if (i >= 2) {
                acc[i] = acc[i - 1] + dpf[i] + dpb[i];
                if (acc[i] > inf) {
                        acc[i] = inf;
                }
        }
        rep(i, n + 1) {
        }
        rep(i, n + 1) {
        }
        rep(i, n) {
                // reverse count
                int lb = 1, ub = n + 1;
                while (ub - lb > 1) {
                        int mid = (lb + ub) / 2;
                        int rest = n - mid;
                        ll c = dpf[rest] + dpb[rest];
                        if (c > k) {
                                lb = mid;
                        } else {
                                ub = mid;
                        }
                }
                for (int j = i + lb - 1; j >= i; j --) {
                        cout << j + 1 << " ";
                }
                i += lb - 1;
        }
        cout << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;

        const int man = 100;
        const ll inf = 1e18 + 10;
        vector<ll> dpf(man + 1), dpb(man + 1);
        dpf[0] = 1, dpf[1] = 1;
        dpb[0] = 1, dpb[1] = 0;
        for (int i = 2; i < man + 1; i ++) {
                dpf[i] = dpf[i - 1] + dpb[i - 1];
                dpb[i] = dpb[i - 1] + dpf[i - 2];
                if (dpf[i] > inf) {
                        dpf[i] = inf;
                }
                if (dpb[i] > inf) {
                        dpb[i] = inf;
                }
        }

        while (t --) {
                solve(dpf, dpb);
        }
        return 0;
}
