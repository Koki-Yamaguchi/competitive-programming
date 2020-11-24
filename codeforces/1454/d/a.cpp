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

void solve() {
        ll n;
        cin >> n;
        auto f = factorize(n);
        int ma = 0;
        ll v = -1;
        for (auto it : f) {
                if (ma < it.second) {
                        ma = it.second;
                        v = it.first;
                }
        }
        ll nn = n;
        while (nn % v == 0) {
                nn /= v;
        }
        cout << ma << '\n';
        rep(i, ma - 1) {
                cout << v << ' ';
        }
        cout << v * nn << '\n';
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
