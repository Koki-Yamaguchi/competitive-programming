#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(m);
        vector<int> cnt(n);
        vector<int> deg(m);
        rep(i, m) {
                cin >> deg[i];
                a[i].resize(deg[i]);
                rep(j, deg[i]) {
                        cin >> a[i][j];
                        a[i][j] --;
                        cnt[a[i][j]] ++;
                }
        }
        int maxc = (m + 1) / 2;
        int mai = -1;
        rep(i, n) {
                if (cnt[i] > maxc) {
                        mai = i;
                        break;
                }
        }
        vector<int> ans(m, -1);
        if (mai == -1) {
                rep(i, m) {
                        if (a[i].size() == 0) {
                                cout << "NO\n";
                                return;
                        }
                        ans[i] = a[i].back() + 1;
                }
                cout << "YES\n";
                cout << ans << '\n';
        } else {
                vector<int> maigo;
                rep(i, m) {
                        rep(j, deg[i]) {
                                if (a[i][j] == mai) {
                                        maigo.push_back(i);
                                }
                        }
                }
                sort(all(maigo), [&](const int a, const int b) {
                        return deg[a] < deg[b];
                });
                assert(maigo.size() > maxc);
                if (deg[maigo[maxc]] == 1) {
                        cout << "NO\n";
                        return;
                }
                rep(i, maxc) {
                        ans[maigo[i]] = mai + 1;
                }
                rep(i, m) {
                        if (ans[i] == -1) {
                                bool ok = false;
                                rep(j, a[i].size()) {
                                        if (a[i][j] != mai) {
                                                ans[i] = a[i][j] + 1;
                                                ok = true;
                                                break;
                                        }
                                }
                                if (not ok) {
                                        cout << "NO\n";
                                        return;
                                }
                        }
                }
                cout << "YES\n";
                cout << ans << '\n';
        }
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
