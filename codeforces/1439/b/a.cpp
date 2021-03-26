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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n);
        vector<int> deg(n);
        rep(i, m) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
                deg[a] ++;
                deg[b] ++;
        }
        queue<int> que;
        vector<bool> dead(n);
        rep(u, n) {
                if (deg[u] < k) {
                        que.push(u);
                }
        }
        while (que.size() > 0) {
                int u = que.front(); que.pop();
                if (deg[u] == k - 1) {
                        set<int> st;
                        st.insert(u);
                        for (int v : g[u]) if (not dead[v]) {
                                st.insert(v);
                        }
                        assert(st.size() == k);
                        bool ok = true;
                        for (int v : g[u]) if (not dead[v]) {
                                int cnt = 0;
                                for (int w : g[v]) if (not dead[w]) {
                                        if (st.count(w)) {
                                                cnt ++;
                                        }
                                }
                                if (cnt != k - 1) {
                                        ok = false;
                                        break;
                                }
                        }
                        if (ok) {
                                cout << 2 << '\n';
                                for (auto val : st) {
                                        cout << val + 1 << ' ';
                                }
                                cout << '\n';
                                return;
                        }
                }
                dead[u] = true;
                for (int v : g[u]) if (not dead[v]) {
                        deg[v] --;
                        if (deg[v] < k) {
                                que.push(v);
                        }
                }
        }
        vector<int> sub;
        rep(i, n) {
                if (not dead[i]) {
                        sub.push_back(i + 1);
                }
        }
        if (sub.size()) {
                cout << 1 << " " << sub.size() << '\n';
                cout << sub << '\n';
                return;
        }
        cout << -1 << '\n';
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
