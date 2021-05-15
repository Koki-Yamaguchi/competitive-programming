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

int get() {
        int r;
        cin >> r;
        return r - 1;
}

void play(int value, int y, int x) {
        cout << value + 1 << " " << y + 1 << " " << x + 1 << endl;
}

void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> a, b;
        rep(i, n) {
                rep(j, n) {
                        if ((i + j) & 1) {
                                a.emplace_back(i, j);
                        } else {
                                b.emplace_back(i, j);
                        }
                }
        }
        int cnt = 0;
        int ap = 0;
        int bp = 0;
        bool resta = false;
        bool restb = false;
        while (true) {
                int v = get();
                if (resta) {
                        if (v != 0) {
                                play(0, a[ap].first, a[ap].second);
                                ap ++;
                        } else {
                                play(2, a[ap].first, a[ap].second);
                                ap ++;
                        }
                } else if (restb) {
                        if (v != 1) {
                                play(1, b[bp].first, b[bp].second);
                                bp ++;
                        } else {
                                play(2, b[bp].first, b[bp].second);
                                bp ++;
                        }
                } else if (v != 0) {
                        play(0, a[ap].first, a[ap].second);
                        ap ++;
                        if (ap == a.size()) {
                                restb = true;
                        }
                } else if (v != 1) {
                        play(1, b[bp].first, b[bp].second);
                        bp ++;
                        if (bp == b.size()) {
                                resta = true;
                        }
                }
                cnt ++;
                if (cnt == n * n) {
                        break;
                }
        }
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
