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
        map<int, int> mir;
        mir[0] = 0;
        mir[1] = 1;
        mir[2] = 5;
        mir[5] = 2;
        mir[3] = -1;
        mir[4] = -1;
        mir[5] = 2;
        mir[6] = -1;
        mir[7] = -1;
        mir[8] = 8;
        mir[9] = -1;
        int h, m;
        cin >> h >> m;
        string t;
        cin >> t;
        string hh = t.substr(0, 2);
        string mm = t.substr(3, 2);
        int hv = stoi(hh);
        int mv = stoi(mm);
        while (true) {
                bool ok = true;
                if (mir[hv % 10] == -1 || mir[hv / 10] == -1 || mir[mv % 10] == -1 || mir[mv / 10] == -1) {
                        ok = false;
                }
                if (ok) {
                        int mirhv = (mir[mv % 10] * 10) + mir[mv / 10];
                        int mirmv = (mir[hv % 10] * 10) + mir[hv / 10];
                        if (mirhv < h && mirmv < m) {
                                cout << (hv < 10 ? "0" : "") << hv << ":" << (mv < 10 ? "0" : "") << mv << '\n';
                                return;
                        }
                }
                mv ++;
                if (mv == m) {
                        mv = 0;
                        hv ++;
                        if (hv == h) {
                                hv = 0;
                        }
                }
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
