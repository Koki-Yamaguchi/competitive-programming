#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        rep(i, n) {
                int sz;
                cin >> sz;
                rep(j, sz) {
                        int d;
                        cin >> d;
                        d --;
                        g[i].push_back(d);
                }
        }
        vector<int> mt0(n, -1), mt1(n, -1);
        rep(i, n) {
                for (int j : g[i]) {
                        if (mt1[j] == -1) {
                                mt0[i] = j;
                                mt1[j] = i;
                                break;
                        }
                }
        }
        int idx0 = find(all(mt0), -1) - mt0.begin();
        int idx1 = find(all(mt1), -1) - mt1.begin();
        if (idx0 != n && idx1 != n) {
                cout << "IMPROVE\n";
                cout << idx0 + 1 << " " << idx1 + 1 << '\n';
                return;
        }
        cout << "OPTIMAL\n";
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
