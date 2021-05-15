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

class prime_table {
public:
        prime_table(int maxn) : maxn(maxn), is_primes(maxn + 1, true) {
                is_primes[0] = is_primes[1] = false;
                for (int i = 2; i <= maxn; i ++) {
                        if (is_primes[i]) {
                                primes.push_back(i);
                                for (int j = i + i; j <= maxn; j += i) is_primes[j] = false;
                        }
                }
        }
        bool is_prime(int n) {
                assert(n <= maxn);
                return is_primes[n];
        }
        vector<int> get_primes() {
                return primes;
        }
private:
        int maxn;
        vector<int> primes;
        vector<bool> is_primes;
};
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

void solve(const vector<ll> &mi, const min_factor_table &mft) {
        ll c;
        cin >> c;
        auto fs = 
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);

        const int maxc = 10000000;
        prime_table pt(maxc);
        min_factor_table mft(maxc);
        auto primes = pt.get_primes();
        vector<ll> mi(maxc + 1);
        for (auto prime : primes) {
                ll s = 1;
                ll b = prime;
                while (true) {
                        s += b;
                        if (s <= maxc) {
                                mi[s] = min(mi[s], prime);
                                b *= prime;
                        } else {
                                break;
                        }
                }
        }

        int t; cin >> t;
        // int t = 1;
        while (t --) {
                solve(mi, mft);
        }
        return 0;
}
