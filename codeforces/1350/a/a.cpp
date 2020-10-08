#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

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
        vector<pair<int, int>> factorize(int n) {
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

void solve() {
        int n, k;
        cin >> n >> k;
        min_factor_table mft(n);
        auto mfs = mft.get_min_factors();
        long long ans = 0;
        ans += mfs[n] + n;
        ans += (long long) (k - 1) * 2;
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
