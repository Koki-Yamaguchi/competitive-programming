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
        set<int> st;
        rep(i, n) {
                cin >> a[i];
                a[i] --;
                st.insert(a[i]);
        }
        vector<int> b;
        rep(i, 2 * n) {
                if (st.count(i) == 0) {
                        b.push_back(i);
                }
        }
        assert(b.size() == n);
        sort(all(a));
        sort(all(b));
        int mi = -1;
        {
                int lb = 0, ub = n + 1; // [lb, ub)
                while (ub - lb > 1) {
                        int x = (lb + ub) / 2;
                        vector<int> aaa, bbb;
                        rep(i, x) {
                                aaa.push_back(a[i]);
                        }
                        for (int i = n - x; i < n; i ++) {
                                bbb.push_back(b[i]);
                        }
                        assert(aaa.size() == bbb.size());
                        bool ng = false;
                        rep(i, x) {
                                if (aaa[i] > bbb[i]) {
                                        ng = true;
                                        break;
                                }
                        }
                        if (ng) {
                                ub = x;
                        } else {
                                lb = x;
                        }
                }
                mi = lb;
        }
        int ma = -1;
        {
                int lb = -1, ub = n; // (lb, ub]
                while (ub - lb > 1) {
                        int x = (lb + ub) / 2;
                        vector<int> aaa, bbb;
                        rep(i, n - x) {
                                bbb.push_back(b[i]);
                        }
                        for (int i = x; i < n; i ++) {
                                aaa.push_back(a[i]);
                        }
                        assert(aaa.size() == bbb.size());
                        bool ng = false;
                        rep(i, n - x) {
                                if (aaa[i] < bbb[i]) {
                                        ng = true;
                                        break;
                                }
                        }
                        if (ng) {
                                lb = x;
                        } else {
                                ub = x;
                        }
                }
                ma = ub;
        }
        cout << mi - ma + 1 << '\n';
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
