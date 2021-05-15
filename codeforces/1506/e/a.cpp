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
                a[i] --;
        }
        set<int> app;
        rep(i, n) {
                app.insert(a[i]);
        }
        vector<int> rest;
        rep(i, n) {
                if (app.count(i) == 0) {
                        rest.push_back(i);
                }
        }
        vector<int> ami;
        {
                int ma = -1;
                int cur = 0;
                set<int> used;
                rep(i, n) {
                        ma = max(ma, a[i]);
                        if (used.count(ma)) {
                                assert(rest.size() > cur);
                                ami.push_back(rest[cur ++] + 1);
                        } else {
                                used.insert(ma);
                                ami.push_back(ma + 1);
                        }
                }
        }
        vector<int> ama;
        {
                int ma = -1;
                int prev = -1;
                priority_queue<int> pq;
                set<int> used;
                rep(i, n) {
                        if (chmax(ma, a[i])) {
                                for (int j = prev + 1; j < rest.size() && rest[j] < a[i]; j ++) {
                                        pq.push(rest[j]);
                                        prev = j;
                                }
                        }
                        if (used.count(ma)) {
                                assert(pq.size());
                                ama.push_back(pq.top() + 1);
                                pq.pop();
                        } else {
                                used.insert(ma);
                                ama.push_back(ma + 1);
                        }
                }
        }
        cout << ami << '\n';
        cout << ama << '\n';
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
