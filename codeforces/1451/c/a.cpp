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
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        map<int, int> cnta, cntb;
        rep(i, n) {
                cnta[a[i] - 'a'] ++;
                cntb[b[i] - 'a'] ++;
        }
        map<int, vector<int>> reva, revb;
        for (auto it : cnta) {
                int c = it.second;
                int d = c / k;
                int e = c % k;
                while (d --) {
                        reva[k].push_back(it.first);
                }
                if (e) reva[e].push_back(it.first);
        }
        for (auto it : cntb) {
                int c = it.second;
                int d = c / k;
                int e = c % k;
                while (d --) {
                        revb[k].push_back(it.first);
                }
                revb[e].push_back(it.first);
        }
        for (auto it : reva) {
                int val = it.first;
                vector<int> vva = it.second;
                vector<int> vvb = revb[val];
                if (vva.size() != vvb.size()) {
                        cout << "No\n";
                        return;
                }
                sort(all(vva));
                sort(all(vvb));
                rep(i, vva.size()) {
                        if ((val != k && (vva[i] != vvb[i])) || vva[i] > vvb[i]) {
                                cout << "No\n";
                                return;
                        }
                }
        }
        cout << "Yes\n";
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
