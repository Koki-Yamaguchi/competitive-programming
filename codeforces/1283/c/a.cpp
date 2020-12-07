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
        vector<int> a(n);
        set<int> from, used_to;
        rep(i, n) {
                cin >> a[i];
                a[i] --;
                if (a[i] == -1) {
                        from.insert(i);
                } else {
                        used_to.insert(a[i]);
                }
        }
        vector<int> to;
        rep(i, n) {
                if (used_to.count(i) == 0) {
                        to.push_back(i);
                }
        }
        set<int> common;
        rep(i, to.size()) {
                if (from.count(to[i]) > 0) {
                        common.insert(to[i]);
                }
        }
        vector<int> fromfrom, toto;
        for (auto it : from) {
                if (common.count(it) > 0) {
                        fromfrom.push_back(it);
                        toto.push_back(it);
                }
        }
        for (auto it : from) {
                if (common.count(it) == 0) {
                        fromfrom.push_back(it);
                }
        }
        for (auto it : to) {
                if (common.count(it) == 0) {
                        toto.push_back(it);
                }
        }
        int sz = fromfrom.size();
        vector<int> res(n);
        rep(i, sz) {
                res[fromfrom[i]] = toto[(i + 1) % sz];
        }
        rep(i, n) {
                if (a[i] == -1) {
                        a[i] = res[i];
                }
        }
        rep(i, n) {
                a[i] ++;
        }
        cout << a << '\n';
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
