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
        int k = 9;
        int mi = 1e9;
        rep(s, 1 << k) {
                int tot = 0;
                rep(i, k) {
                        if ((s >> i) & 1) {
                                tot += i + 1;
                        }
                }
                if (tot == n) {
                        int v = 0;
                        rep(i, k) {
                                if ((s >> i) & 1) {
                                        v *= 10;
                                        v += i + 1;
                                }
                        }
                        mi = min(mi, v);
                }
        }
        if (mi != 1e9) {
                cout << mi << '\n';
        } else {
                cout << "-1\n";
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
