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

int CNT = 0;

int ask(int l, int r) { // [l, r)
        if (l + 1 == r) {
                return -1;
        }
        cout << "? " << l + 1 << " " << r << endl;
        int res;
        cin >> res;
        CNT ++;
        return res - 1;
}

void answer(int i) {
        cout << "! " << i + 1 << endl;
        return;
}

void solve() {
        int n;
        cin >> n;
        int sg = ask(0, n);
        int lsg = ask(0, sg + 1);
        int rsg = ask(sg, n);
        if (sg == lsg) {
                int x = sg + 1; // x)
                int lb = 0;
                int ub = x;
                while (ub - lb > 1) {
                        int mid = (lb + ub) / 2;
                        int msg = ask(mid, x);
                        if (msg == sg) {
                                lb = mid;
                        } else {
                                ub = mid;
                        }
                }
                assert(CNT <= 20);
                answer(lb);
        } else {
                int x = sg; // [x,
                int lb = sg + 1;
                int ub = n;
                while (ub - lb > 1) {
                        int mid = (lb + ub) / 2;
                        int msg = ask(x, mid);
                        if (msg == sg) {
                                ub = mid;
                        } else {
                                lb = mid;
                        }
                }
                assert(CNT <= 20);
                answer(lb);
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
