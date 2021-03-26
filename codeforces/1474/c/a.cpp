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
        int n;
        cin >> n;
        n *= 2;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        sort(all(a));
        vector<pair<int, int>> ans;
        for (int p = n - 2; p >= 0; p --) {
                vector<bool> used(n);
                map<int, int> usedc;
                int x = a[n - 1];
                int y = a[p];
                used[n - 1] = true;
                used[p] = true;
                usedc[x] ++;
                usedc[y] ++;
                int curi = n - 1;
                bool ok = true;
                ans.emplace_back(x, y);
                int hoge = x, fuga = y;
                while (true) {
                        while (curi >= 0 && used[curi]) {
                                curi --;
                        }
                        if (curi == -1) {
                                break;
                        }
                        int cur = a[curi];
                        used[curi] = true;
                        usedc[cur] ++;
                        int other = x - cur;
                        if (other > cur) {
                                ok = false;
                                break;
                        }
                        // dump(cur);
                        // dump(other);
                        int pos = upper_bound(all(a), other) - a.begin();
                        pos --;
                        if (pos < 0) {
                                ok = false;
                                break;
                        }
                        int val = a[pos];
                        if (val != other) {
                                ok = false;
                                break;
                        }
                        int idx = pos - usedc[val];
                        if (idx >= n || a[idx] != val) {
                                ok = false;
                                break;
                        }
                        usedc[val] ++;
                        assert(not used[idx]);
                        used[idx] = true;
                        ans.emplace_back(cur, other);
                        x = cur;
                }
                if (ok) {
                        cout << "YES\n";
                        cout << hoge + fuga << '\n';
                        assert(ans.size() == n / 2);
                        rep(i, n / 2) {
                                cout << ans[i] << '\n';
                        }
                        return;
                } else {
                        ans.clear();
                }
        }
        cout << "NO\n";
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
