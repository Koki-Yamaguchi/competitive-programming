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
        vector<int> a(n), t(n);
        rep(i, n) {
                cin >> a[i];
        }
        rep(i, n) {
                cin >> t[i];
        }
        vector<pair<int, int>> p(n);
        rep(i, n) {
                p[i] = make_pair(a[i], t[i]);
        }
        sort(all(p));
        priority_queue<int> que;
        ll sum = 0;
        ll ans = 0;
        int cur = p[0].first;
        rep(i, n) {
                if (cur == p[i].first) {
                        while (i < n - 1 && p[i].first == p[i + 1].first) {
                                que.push(p[i].second);
                                sum += p[i].second;
                                i ++;
                        }
                        que.push(p[i].second);
                        sum += p[i].second;
                        i ++;
                }
                if (que.size() > 0) {
                        sum -= que.top();
                        que.pop();
                        ans += sum;
                        cur ++;
                } else {
                        cur = p[i].first;
                }
                i --;
        }
        while (que.size() > 0) {
                sum -= que.top();
                que.pop();
                ans += sum;
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
