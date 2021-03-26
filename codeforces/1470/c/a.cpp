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
        int n = 10;
        int k = 8;
        vector<int> a(n, k);
        int c = 20;
        int p = 2;
        while (c --) {
                dump(a);
                vector<int> nxt(n);
                rep(i, n) {
                        if (i == p) {
                                nxt[i + 1] += a[i];
                        } else {
                                int l = a[i] / 2;
                                int r = a[i] - l;
                                nxt[((i - 1) + n) % n] += l;
                                nxt[(i + 1) % n] += r;
                        }
                }
                swap(a, nxt);
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
