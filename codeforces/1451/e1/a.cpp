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
        int cnt = 0;
        auto ask = [&](string type, int a, int b) {
                cnt ++;
                cout << type << " " << a << " " << b << endl;
                int v;
                cin >> v;
                return v;
        };
        int p0 = ask("AND", 1, 2);
        int p1 = ask("OR", 1, 2);
        int q0 = ask("AND", 1, 3);
        int q1 = ask("OR", 1, 3);
        int r = ask("AND", 2, 3);
        int a0 = 0;
        rep(i, 20) {
                int p0v = (p0 >> i) & 1;
                int p1v = (p1 >> i) & 1;
                int q0v = (q0 >> i) & 1;
                int q1v = (q1 >> i) & 1;
                if ((p0v == 1 && p1v == 1) || (q0v == 1 && q1v == 1)) {
                        a0 |= (1 << i);
                } else if ((p0v == 0 && p1v == 0) || (q0v == 0 && q1v == 0)) {
                        // 0
                } else {
                        if ((r >> i) & 1) {
                                // 0
                        } else {
                                a0 |= 1 << i;
                        }
                }
        }
        int a1 = 0, a2 = 0;
        rep(i, 20) {
                int p0v = (p0 >> i) & 1;
                int p1v = (p1 >> i) & 1;
                if (p0v == 1 && p1v == 1) {
                        a1 |= (1 << i);
                } else if (p0v == 0 && p1v == 0) {
                        // 0
                } else {
                        if ((a0 >> i) & 1) {
                                // 0
                        } else {
                                a1 |= 1 << i;
                        }
                }
        }
        rep(i, 20) {
                int q0v = (q0 >> i) & 1;
                int q1v = (q1 >> i) & 1;
                if (q0v == 1 && q1v == 1) {
                        a2 |= (1 << i);
                } else if (q0v == 0 && q1v == 0) {
                        // 0
                } else {
                        if ((a0 >> i) & 1) {
                                // 0
                        } else {
                                a2 |= 1 << i;
                        }
                }
        }
        vector<int> ans;
        ans.push_back(a0);
        ans.push_back(a1);
        ans.push_back(a2);
        for (int i = 3; i < n; i ++) {
                int v = ask("XOR", 1, i + 1);
                int rs = 0;
                rep(i, 20) {
                        if (((v >> i) & 1) && !((a0 >> i) & 1)) {
                                rs |= 1 << i;
                        } else if (!((v >> i) & 1) && ((a0 >> i) & 1)) {
                                rs |= 1 << i;
                        }
                }
                ans.push_back(rs);
        }
        assert(cnt <= n + 2);
        cout << "! " << ans << endl;
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
