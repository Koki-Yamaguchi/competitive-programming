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
        int n, q;
        cin >> n >> q;
        vector<vector<bool>> s(2, vector<bool> (n));
        int cnt = 0;
        while (q --) {
                int y, x;
                cin >> y >> x;
                y --, x --;
                s[y][x] = not s[y][x];
                if (s[y][x]) {
                        if (s[1 - y][x]) {
                                if (x && not s[y][x - 1]) {
                                        cnt ++;
                                }
                                if (x < n - 1 && not s[y][x + 1]) {
                                        cnt ++;
                                }
                        } else {
                                if (x && not s[y][x - 1] && s[1 - y][x - 1]) {
                                        cnt ++;
                                }
                                if (x < n - 1 && not s[y][x + 1] && s[1 - y][x + 1]) {
                                        cnt ++;
                                }
                        }
                } else {
                        if (s[1 - y][x]) {
                                if (x && not s[y][x - 1]) {
                                        cnt --;
                                }
                                if (x < n - 1 && not s[y][x + 1]) {
                                        cnt --;
                                }
                        } else {
                                if (x && not s[y][x - 1] && s[1 - y][x - 1]) {
                                        cnt --;
                                }
                                if (x < n - 1 && not s[y][x + 1] && s[1 - y][x + 1]) {
                                        cnt --;
                                }
                        }
                }
                assert(0 <= cnt && cnt < n);
                if (cnt == 0) {
                        cout << "Yes\n";
                } else {
                        cout << "No\n";
                }
        }
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
