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

void solve() {
        int n;
        cin >> n;
        ll s = 0;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
                s += a[i];
        }
        vector<int> can;
        for (ll i = 1; i * i <= s; i ++) {
                if (s % i == 0) {
                        can.push_back(i);
                        can.push_back(s / i);
                }
        }
        sort(all(can));
        rep(i, can.size()) {
                int v = can[i];
                int cur = 0;
                bool ng = false;
                rep(j, n) {
                        if (cur + a[j] == v) {
                                cur = 0;
                        } else if (cur + a[j] > v) {
                                ng = true;
                                break;
                        } else {
                                cur += a[j];
                        }
                }
                if (ng) {
                        continue;
                }
                cout << n - s / v << '\n';
                return;
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
