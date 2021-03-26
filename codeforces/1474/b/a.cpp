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

void solve(const vector<int> &ps) {
        int d;
        cin >> d;
        int a = 1 + d;
        int pos = lower_bound(all(ps), a) - ps.begin();
        assert(pos < ps.size());
        int p0 = ps[pos];
        int b = p0 + d;
        pos = lower_bound(all(ps), b) - ps.begin();
        assert(pos < ps.size());
        int p1 = ps[pos];
        cout << (ll) p0 * p1 << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        prime_table pt(100000);
        auto ps = pt.get_primes();
        // int t = 1;
        while (t --) {
                solve(ps);
        }
        return 0;
}
