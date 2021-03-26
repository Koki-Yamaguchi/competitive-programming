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

class min_factor_table {
public:
        min_factor_table(int maxn) : maxn(maxn), min_factors(maxn + 1, -1) {
                min_factors[0] = 0;
                min_factors[1] = 1;
                for (int i = 2; i <= maxn; i ++) {
                        if (min_factors[i] == -1) {
                                min_factors[i] = i;
                                for (int j = i + i; j <= maxn; j += i) {
                                        if (min_factors[j] == -1) {
                                                min_factors[j] = i;
                                        }
                                }
                        }
                }
        }
        vector<int> get_min_factors() {
                return min_factors;
        }
        vector<pair<int, int>> factorize(int n) const {
                assert(1 < n && n <= maxn);
                vector<pair<int, int>> res;
                while (n > 1) {
                        int p = min_factors[n];
                        int c = 0;
                        while (n % p == 0) {
                                n /= p;
                                c ++;
                        }
                        res.emplace_back(p, c);
                }
                return res;
        }
private:
        int maxn;
        vector<int> min_factors;
};

const int maa = 1000000;

void solve(const min_factor_table &mft) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<int> v;
        rep(i, n) {
                if (a[i] == 1) {
                        v.push_back(1);
                        continue;
                }
                auto ps = mft.factorize(a[i]);
                int r = 1;
                for (auto p : ps) {
                        if (p.second & 1) {
                                r *= p.first;
                        }
                }
                v.push_back(r);
        }
        map<int, int> cnt;
        rep(i, n) {
                cnt[v[i]] ++;
        }
        int ans0 = 0;
        for (auto it : cnt) {
                ans0 = max(ans0, it.second);
        }
        int ans = ans0;
        int res = 0;
        rep(i, n) {
                if (v[i] == 1) {
                        res ++;
                } else if (cnt[v[i]] % 2 == 0) {
                        res ++;
                }
        }
        ans = max(ans, res);
        int q;
        cin >> q;
        while (q --) {
                ll w;
                cin >> w;
                if (w) {
                        cout << ans << '\n';
                } else {
                        cout << ans0 << '\n';
                }
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);

        min_factor_table mft(maa);

        int t; cin >> t;
        // int t = 1;
        while (t --) {
                solve(mft);
        }
        return 0;
}
