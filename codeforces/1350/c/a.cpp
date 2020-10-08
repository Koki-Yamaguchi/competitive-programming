#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

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
        map<int, vector<int>> g;
        rep(i, n) {
                int a;
                cin >> a;
                if (a == 1) {
                        continue;
                }
                auto fs = factorize(a);
                for (auto f : fs) {
                        g[f.first].push_back(f.second);
                }
        }
        long long ans = 1;
        for (auto it : g) {
                /*
                cerr << "it.first = " << it.first << endl;
                for (auto v : it.second) {
                        cerr << v << " ";
                }
                cerr << endl;
                */
                sort(it.second.begin(), it.second.end());
                if (it.second.size() == n) {
                        int c = it.second[1];
                        while (c --) {
                                ans *= it.first;
                        }
                } else if (it.second.size() == n - 1) {
                        int c = it.second[0];
                        while (c --) {
                                ans *= it.first;
                        }
                }
        }
        cout << ans << '\n';
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
