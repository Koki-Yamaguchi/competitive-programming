#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long gcd(long long a, long long b) {
        while (b) {
                a %= b;
                swap(a, b);
        }
        return a;
}

long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
}

void solve() {
        int n;
        cin >> n;
        long long mi = 1e18;
        vector<int> cands;
        for (int i = 1; i * i <= n; i ++) {
                if (n % i == 0) {
                        int o = n / i;
                        cands.push_back(i);
                        cands.push_back(o);
                }
        }
        int a = -1, b = -1;
        for (int c : cands) {
                int o = n - c;
                if (o > 0) {
                        long long l = lcm(c, o);
                        if (mi > l) {
                                mi = l;
                                a = c, b = o;
                        }
                }
        }
        assert(a != -1 && b != -1);
        cout << a << " " << b << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
