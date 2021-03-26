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

void solve(const vector<ll> &cubes, const set<ll> &st) {
        ll x;
        cin >> x;
        rep(i, cubes.size()) {
                if (x > cubes[i]) {
                        ll rest = x - cubes[i];
                        if (st.count(rest)) {
                                cout << "YES\n";
                                return;
                        }
                }
        }
        cout << "NO\n";
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t; cin >> t;
        // int t = 1;
        vector<ll> cubes;
        set<ll> st;
        rep(i, 10001) if (i) {
                cubes.push_back((ll) i * i * i);
                st.insert((ll) i * i * i);
        }
        while (t --) {
                solve(cubes, st);
        }
        return 0;
}
