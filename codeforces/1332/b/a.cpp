#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

template<class T>
vector<pair<T, int>> factorize(T n) {
        assert(n > 1);
        vector<pair<T, int>> res;
        for (T i = 2; i * i <= n; i ++) {
                if (n % i == 0) {
                        int c = 0;
                        while (n % i == 0) {
                                n /= i;
                                c ++;
                        }
                        res.emplace_back(i, c);
                }
        }
        if (n > 1) {
                res.emplace_back(n, 1);
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        vector<int> ans(n, -1);
        rep(i, n) {
                cin >> a[i];
                auto f = factorize(a[i]);
                for (auto it : f) {
                        rep(j, ps.size()) {
                                if (it.first == ps[j]) {
                                        ans[i] = j;
                                        break;
                                }
                        }
                        if (ans[i] != -1) {
                                break;
                        }
                }
        }
        map<int, int> z;
        int k = 0;
        rep(i, n) {
                if (z.count(ans[i]) == 0) z[ans[i]] = k ++;
        }
        cout << k << '\n';
        rep(i, n) {
                cout << z[ans[i]] + 1 << " \n"[i == n - 1];
        }
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
