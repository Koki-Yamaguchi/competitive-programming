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

int ask(int p) {
        cout << "? " << p + 1 << endl;
        int v;
        cin >> v;
        return v;
}

void answer(int p) {
        cout << "! " << p + 1 << endl;
        return;
}

void solve() {
        int n;
        cin >> n;
        if (n == 1) {
                answer(0);
                return;
        }
        int l0 = ask(0);
        int l1 = ask(1);
        if (l0 < l1) {
                answer(0);
                return;
        }
        int r0 = ask(n - 1);
        int r1 = ask(n - 2);
        if (r0 < r1) {
                answer(n - 1);
                return;
        }
        int lb = 0, ub = n - 1; // > ... <
        while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                int midl = mid;
                int midr = mid + 1;
                int vl = ask(midl);
                int vr = ask(midr);
                if (vl < vr) {
                        ub = mid;
                } else {
                        lb = mid;
                }
        }
        answer(lb + 1);
        return;
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
