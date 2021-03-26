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

vector<int> calc(vector<int> &a, const int k) {
        cerr << "IN" << endl;
        dump(a);
        int n = a.size();
        int hlf = n / 2;
        vector<vector<int>> cur(k, vector<int> (hlf + 1, -1e9));
        rep(i, hlf + 1) {
                cur[0][i] = 0;
        }
        rep(i, n) {
                auto nxt = cur;
                rep(s, hlf + 1) {
                        rep(t, k) {
                                if (s < hlf && cur[t][s] >= 0) {
                                        int &r = nxt[(t + a[i]) % k][s + 1];
                                        r = max(r, cur[t][s] + a[i]);
                                }
                        }
                }
                rep(j, k) {
                        cerr << "mod " << j << endl;
                        dump(nxt[j]);
                }
                swap(cur, nxt);
        }
        vector<int> res(k);
        rep(i, k) {
                res[i] = *max_element(all(cur[i]));
        }
        cerr << "OUT" << endl;
        return res;
}

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int> (m));
        rep(i, n) {
                rep(j, m) {
                        cin >> a[i][j];
                }
        }
        vector<int> cur(k);
        rep(i, n) {
                auto res = calc(a[i], k);
                dump(res);
                vector<int> nxt(k);
                rep(p, k) {
                        rep(q, k) {
                                nxt[(p + q) % k] = max(nxt[(p + q) % k], cur[p] + res[q]);
                        }
                }
                swap(cur, nxt);
        }
        dump(cur);
        cout << cur[0] << '\n';
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
