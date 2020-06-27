#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
string get(int x) {
        int p = x / 9;
        string res = string(p, '9');
        int d = x % 9;
        res = to_string(d) + res;
        return res;
}
 
string get2(int x) {
        string res;
        if (x >= 8) {
                res = "8";
                x -= 8;
        }
        int p = x / 9;
        res = string(p, '9') + res;
        int d = x % 9;
        res = to_string(d) + res;
        return res;
}
 
void solve() {
        int n, k;
        cin >> n >> k;
        long long ans = 1e18;
 
        for (int i = 0; i <= 9 - k; i ++) {
                int s = i * (k + 1) + k * (k + 1) / 2;
                if (n - s >= 0 && (n - s) % (k + 1) == 0) {
                        int d = (n - s) / (k + 1);
                        string pre = get(d);
                        pre += to_string(i);
                        long long p = stoll(pre);
                        ans = min(ans, p);
                }
        }
 
        for (int a = 1; a <= k; a ++) {
                int b = k + 1 - a;
                for (int p = 1; p <= 17; p ++) {
                        int s = a * 9 * p - a * (a - 1) / 2 + b * (b + 1) / 2;
                        if (n - s >= 0 && (n - s) % (a + b) == 0) {
                                int d = (n - s) / (a + b);
                                string pre = get2(d);
                                pre += string(p - 1, '9');
                                pre += to_string(10 - a);
                                long long r = stoll(pre);
                                ans = min(ans, r);
                        }
                }
        }
 
        if (ans == 1e18) ans = -1;
        cout << ans << '\n';
}
 
int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
}