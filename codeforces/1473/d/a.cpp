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

template<typename F, typename T>
struct segment_tree {
        F merge;
        T identity;
        vector<T> data;
        int n;
        segment_tree(int len, F _merge, T _identity) : merge(_merge), identity(_identity) {
                n = pow(2, ceil(log2(len)));
                data.resize(2 * n - 1, identity); 
        }
        // update k-th value to p
        void update(int k, T p) {
                k += n - 1;
                data[k] = p;
                while (k > 0) {
                        k = (k - 1) / 2;
                        data[k] = merge(data[k * 2 + 1], data[k * 2 + 2]);
                }
        }
        // [l, r)
        T query(int l, int r) { return query(l, r, 0, 0, n); }
        T query(int a, int b, int k, int l, int r) {
                if (r <= a || b <= l) return identity;
                if (a <= l && r <= b) return data[k];
                int m = (l + r) / 2;
                return merge(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
        }
};

void solve() {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> pc(n + 1), nc(n + 1);
        rep(i, n) {
                pc[i + 1] = pc[i] + (s[i] == '+');
                nc[i + 1] = nc[i] + (s[i] == '-');
        }
        vector<int> acc(n + 1);
        rep(i, n) {
                acc[i + 1] = acc[i] + (s[i] == '+' ? 1 : -1);
        }
        auto fmi = [&](int a, int b) { return min(a, b); };
        auto fma = [&](int a, int b) { return max(a, b); };
        const int inf = 1e9;
        segment_tree<decltype(fmi), int> segmi(n + 1, fmi, inf);
        segment_tree<decltype(fma), int> segma(n + 1, fma, -inf);
        rep(i, n + 1) {
                segmi.update(i, acc[i]);
                segma.update(i, acc[i]);
        }
        rep(i, q) {
                int l, r;
                cin >> l >> r;
                l --;
                int pcnt = pc[r] - pc[l];
                int ncnt = nc[r] - nc[l];
                int diff = pcnt - ncnt;
                int mi = inf;
                int ma = -inf;
                chmin(mi, segmi.query(0, l));
                chmin(mi, segmi.query(r, n + 1) - diff);
                chmax(ma, segma.query(0, l));
                chmax(ma, segma.query(r, n + 1) - diff);
                cout << ma - mi + 1 << '\n';
        }
        cerr << endl;
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
