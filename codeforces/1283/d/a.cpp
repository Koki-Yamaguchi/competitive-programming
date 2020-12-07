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
        int n, m;
        cin >> n >> m;
        vector<ll> x;
        set<ll> used;
        rep(i, n) {
                ll tmp;
                cin >> tmp;
                x.push_back(tmp);
                used.insert(tmp);
        }
        priority_queue<pair<int, ll>> que; // -d, pos
        rep(i, n) {
                for (int d = -1; d <= 1; d += 2) {
                        ll xx = x[i] + d;
                        if (used.count(xx) == 0) {
                                que.push({-1, xx});
                                used.insert(xx);
                        }
                }
        }
        ll tot = 0;
        vector<ll> ans;
        while (true) {
                auto q = que.top(); que.pop();
                int curd = q.first * -1;
                ll v = q.second;
                tot += curd;
                ans.push_back(v);
                if (ans.size() == m) {
                        break;
                }
                for (int d = -1; d <= 1; d += 2) {
                        ll vv = v + d;
                        if (used.count(vv) == 0) {
                                que.push({-(curd + 1), vv});
                                used.insert(vv);
                        }
                }
        }
        cout << tot << '\n';
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
