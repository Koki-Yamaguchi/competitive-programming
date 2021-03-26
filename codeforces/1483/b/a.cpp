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
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<pair<int, int>> sides(n);
        rep(i, n) {
                sides[i].first = (i - 1 + n) % n;
                sides[i].second = (i + 1) % n;
        }
        vector<bool> deled(n);
        auto del = [&](int idx) {
                assert(not deled[idx]);
                deled[idx] = true;
                int left = sides[idx].first;
                int right = sides[idx].second;
                sides[left].second = right;
                sides[right].first = left;
        };
        queue<int> que;
        set<int> in;
        rep(i, n) if (i) {
                int g = gcd(a[i], a[i - 1]);
                if (g == 1) {
                        que.push(i);
                        in.insert(i);
                        i ++;
                }
        }
        que.push(0);
        in.insert(0);
        vector<int> ans;
        int ignore = -1;
        while (not que.empty()) {
                int idx = que.front(); que.pop();
                if (ignore == idx) {
                        ignore = -1;
                        que.push(idx);
                        continue;
                }
                in.erase(idx);
                auto [li, ri] = sides[idx];
                int g = gcd(a[li], a[idx]);
                if (g == 1) {
                        del(idx);
                        ans.push_back(idx + 1);
                        ignore = ri;
                        if (ans.size() == n) {
                                break;
                        }
                        if (in.count(ri) == 0) {
                                que.push(ri);
                                in.insert(ri);
                        }
                }
        }
        cout << ans.size();
        if (ans.size() > 0) {
                cout << " " << ans;
        }
        cout << '\n';
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
