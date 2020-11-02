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

const int MOD = 998244353;

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k);
        map<int, int> pos;
        rep(i, n) {
                cin >> a[i];
                pos[a[i]] = i;
        }
        map<int, int> idx;
        rep(i, k) {
                cin >> b[i];
                idx[b[i]] = i;
        }
        vector<pair<int, int>> to(n);
        rep(i, n) {
                if (i == 0) {
                        to[i] = make_pair(-1, 1);
                } else if (i == n - 1) {
                        to[i] = make_pair(n - 2, -1);
                } else {
                        to[i] = make_pair(i - 1, i + 1);
                }
        }
        /*
        cerr << "TO" << endl;
        rep(i, n) {
                cerr << to[i].first << " " << to[i].second << '\n';
        }
        */
        auto cut = [&](int p) {
                int left = to[p].first;
                int right = to[p].second;

                if (left != -1) {
                        to[left].second = right;
                }
                if (right != -1) {
                        to[right].first = left;
                }
        };
        ll ans = 1;
        rep(i, k) {
                if (pos.count(b[i]) == 0) {
                        cout << 0 << '\n';
                        return;
                }
                int p = pos[b[i]];
                int mid = a[p];

                bool left_ok = (to[p].first != -1);
                if (left_ok) {
                        int left = a[to[p].first];
                        left_ok = left_ok && (idx.count(left) == 0 || idx[mid] > idx[left]);
                }

                bool right_ok = (to[p].second != -1);
                if (right_ok) {
                        int right = a[to[p].second];
                        right_ok = right_ok && (idx.count(right) == 0 || idx[mid] > idx[right]);
                }

                if (left_ok && right_ok) {
                        (ans *= 2) %= MOD;
                        cut(p);
                } else if (left_ok) {
                        cut(to[p].first);
                } else if (right_ok) {
                        cut(to[p].second);
                } else {
                        cout << 0 << '\n';
                        return;
                }
                /*
                cerr << "TO" << endl;
                rep(i, n) {
                        cerr << to[i].first << " " << to[i].second << '\n';
                }
                */
        }
        cout << ans << '\n';
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
