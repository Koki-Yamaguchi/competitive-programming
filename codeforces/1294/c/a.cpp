#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p) {
        os << p.first << " " << p.second;
        return os;
}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

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

int poww(int n, int x) {
        int res = 1;
        while (x --) {
                res *= n;
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        auto f = factorize(n);
        vector<int> ans;
        if (f.size() >= 3) {
                rep(i, 3) {
                        ans.push_back(poww(f[i].first, f[i].second));
                }
                for (int i = 3; i < f.size(); i ++) {
                        ans.back() *= poww(f[i].first, f[i].second);
                }
        } else if (f.size() == 2) {
                if (f[0].second >= 2 && f[1].second >= 2) {
                        ans.push_back(f[0].first * f[1].first);
                        ans.push_back(poww(f[0].first, f[0].second - 1));
                        ans.push_back(poww(f[1].first, f[1].second - 1));
                } else if (f[0].second >= 3) {
                        ans.push_back(f[0].first);
                        ans.push_back(f[1].first);
                        ans.push_back(poww(f[0].first, f[0].second - 1));
                } else if (f[1].second >= 3) {
                        ans.push_back(f[0].first);
                        ans.push_back(f[1].first);
                        ans.push_back(poww(f[1].first, f[1].second - 1));
                } else {
                        cout << "NO\n";
                        return;
                }
        } else {
                if (f[0].second >= 6) {
                        ans.push_back(f[0].first);
                        ans.push_back(f[0].first * f[0].first);
                        ans.push_back(poww(f[0].first, f[0].second - 3));
                } else {
                        cout << "NO\n";
                        return;
                }
        }
        assert(ans[0] * ans[1] * ans[2]);
        cout << "YES\n";
        cout << ans << "\n";
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
