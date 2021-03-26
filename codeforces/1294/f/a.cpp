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
		os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
	}
	return os;
}

void solve() {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        int ls = 0;
        int root = -1;
        rep(i, n) {
                ls += g[i].size() == 1;
                if (g[i].size() > 1) {
                        root = i;
                }
        }
        if (ls == 2) {
                int u = -1, v = -1;
                rep(i, n) {
                        if (g[i].size() == 1 && u == -1) {
                                u = i;
                        } else if (g[i].size() == 1 && v == -1) {
                                v = i;
                        }
                }
                assert(u != -1 && v != -1);
                cout << n - 1 << '\n';
                cout << u + 1 << " " << v + 1 << " " << root + 1 << '\n';
                return;
        }
        vector<vector<int>> dp(n, vector<int> (4, -1e9)); // dp[u][cnt] take cnt vertices on subtree u
        vector<int> ch1(n, -1);
        vector<pair<int, int>> ch2(n, {-1, -1});
        vector<pair<pair<int, int>, int>> ch3(n, {{-1, -1}, -1});
        dump(root);
        auto dfs = [&](auto self, int u, int prev) -> void {
                dump(u);
                vector<pair<int, int>> one, two;
                for (int v : g[u]) if (v != prev) {
                        self(self, v, u);
                        if (g[v].size() == 1) {
                                ch1[u] = v;
                        }
                        if (dp[u][1] < dp[v][1] + 1) {
                                ch1[u] = ch1[v];
                        }
                        dp[u][1] = max(dp[u][1], dp[v][1] + 1);
                        if (dp[v][2] != 0) {
                                if (dp[u][2] < dp[v][2] + 1) {
                                        ch2[u] = ch2[v];
                                }
                                dp[u][2] = max(dp[u][2], dp[v][2] + 1);
                        }
                        if (dp[v][3] != 0) {
                                if (dp[u][3] < dp[v][3]) {
                                        ch3[u] = ch3[v];
                                }
                                dp[u][3] = max(dp[u][3], dp[v][3]);
                        }
                        one.push_back({dp[v][1], v});
                        if (dp[v][2] != 0) two.push_back({dp[v][2], v});
                }
                sort(rall(one));
                sort(rall(two));
                if (one.size() >= 2) {
                        if (dp[u][2] < one[0].first + one[1].first + 2) {
                                ch2[u] = make_pair(ch1[one[0].second], ch1[one[1].second]);
                        }
                        dp[u][2] = max(dp[u][2], one[0].first + one[1].first + 2);

                        if (one.size() >= 3) {
                                if (dp[u][3] < one[0].first + one[1].first + one[2].first + 3) {
                                        ch3[u] = make_pair(make_pair(ch1[one[0].second], ch1[one[1].second]), ch1[one[2].second]);
                                }
                                dp[u][3] = max(dp[u][3], one[0].first + one[1].first + one[2].first + 3);
                        }
                }
                if (one.size() >= 1 && two.size() >= 1) {
                        if (one[0].second != two[0].second) {
                                if (dp[u][3] < one[0].first + two[0].first + 2) {
                                        ch3[u] = {ch2[two[0].second], ch1[one[0].second]};
                                }
                                dp[u][3] = max(dp[u][3], one[0].first + two[0].first + 2);
                        } else {
                                if (one.size() >= 2) {
                                        if (dp[u][3], one[1].first + two[0].first + 2) {
                                                ch3[u] = {ch2[two[0].second], ch1[one[1].second]};
                                        }
                                        dp[u][3] = max(dp[u][3], one[1].first + two[0].first + 2);
                                }
                                if (two.size() >= 2) {
                                        if (dp[u][3], one[0].first + two[1].first + 2) {
                                                ch3[u] = {ch2[two[1].second], ch1[one[0].second]};
                                        }
                                        dp[u][3] = max(dp[u][3], one[0].first + two[1].first + 2);
                                }
                        }
                }
                dump(u);
                dump(ch1);
                dump(ch2);
                dump(ch3);
        };
        dfs(dfs, root, -1);
        cout << dp[root][3] << '\n';
        cout << ch3[root].first.first + 1 << " " << ch3[root].first.second + 1 << " " << ch3[root].second + 1 << '\n';
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
