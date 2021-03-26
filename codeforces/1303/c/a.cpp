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
        string s;
        cin >> s;
        int n = s.size();
        vector<set<int>> g(26);
        rep(i, n - 1) {
                int u = s[i] - 'a';
                int v = s[i + 1] - 'a';
                g[u].insert(v);
                g[v].insert(u);
        }
        rep(i, 26) {
                if (g[i].size() > 2) {
                        cout << "NO\n";
                        return;
                }
        }
        string ans;
        vector<bool> used(26);
        int usedc = 0;
        rep(i, 26) {
                if (g[i].size() == 0) {
                        ans.push_back((char) (i + 'a'));
                        used[i] = true;
                        usedc ++;
                }
        }
        int bg = -1;
        rep(i, 26) {
                if (g[i].size() == 1) {
                        bg = i;
                        break;
                }
        }
        if (bg == -1) {
                cout << "NO\n";
                return;
        }
        int cur = bg;
        int prev = -1;
        bool f = true;
        used[cur] = true;
        ans.push_back((char) (cur + 'a'));
        usedc ++;
        /*
        rep(i, 26) {
                dump(i);
                for (auto it : g[i]) {
                        dump(it);
                }
        }
        */
        while (f) {
                int ccc = cur;
                for (auto v : g[ccc]) {
                        if (v != prev) {
                                cerr << "IN" << '\n';
                                if (used[v]) {
                                        cout << "NO\n";
                                        return;
                                }
                                used[v] = true;
                                usedc ++;
                                ans.push_back((char) (v + 'a'));
                                prev = cur;
                                cur = v;
                                if (usedc == 26) {
                                        goto end;
                                }
                        }
                }
        }
        end:;
        cout << "YES\n";
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
