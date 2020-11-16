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
        ll w;
        cin >> n >> w;
        vector<pair<int, int>> a(n);
        rep(i, n) {
                cin >> a[i].first;
                a[i].second = i;
        }
        sort(all(a));
        ll hf = (w + 1) / 2;
        vector<pair<int, int>> can;
        rep(i, n) {
                if (hf <= a[i].first && a[i].first <= w) {
                        cout << 1 << '\n';
                        cout << a[i].second + 1 << '\n';
                        return;
                } else if (a[i].first < hf) {
                        can.emplace_back(a[i]);
                }
        }
        ll sum = 0;
        vector<int> ans;
        rep(i, can.size()) {
                sum += can[i].first;
                ans.push_back(can[i].second + 1);
                assert(sum <= w);
                if (sum >= hf) {
                        break;
                }
        }
        sort(all(ans));
        if (sum >= hf) {
                cout << ans.size() << '\n';
                cout << ans << '\n';
        } else {
                cout << -1 << '\n';
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
