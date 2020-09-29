#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        long long n;
        int s;
        cin >> n >> s;
        auto get = [&](long long a) {
                int res = 0;
                while (a) {
                        res += a % 10;
                        a /= 10;
                }
                return res;
        };
        auto digit = [&](long long a, int d) {
                while (d --) {
                        a /= 10;
                        if (a == 0) {
                                return -1ll;
                        }
                }
                return (a % 10);
        };
        if (get(n) <= s) {
                cout << 0 << '\n';
                return;
        }
        long long b = 1;
        long long prev = 0;
        rep(i, 18) {
                int d = digit(n, i) + (prev != 0);
                int c = 10 - d;
                long long add = (long long) c * b + prev;
                // cerr << "add = " << add << endl;
                if (get(n + add) <= s) {
                        cout << add << '\n';
                        break;
                }
                b *= 10;
                prev = add;
        }
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
