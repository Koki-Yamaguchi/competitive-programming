#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) {
                cin >> a[i];
        }
        vector<vector<int>> ans;
        while (true) {
                int il = -1, jr = -1;
                rep(j, n) {
                        rep(i, j) {
                                if (a[i] == a[j] + 1) {
                                        il = i;
                                        jr = j + 1;
                                        break;
                                }
                        }
                }
                if (il == -1) {
                        break;
                }
                int ir = il;
                while (a[ir] + 1 == a[ir + 1]) {
                        ir ++;
                }
                int jl = jr - 1;
                while (a[jl] - 1 == a[jl - 1]) {
                        jl --;
                }
                if (ir != jl) {
                        ir = jl;
                }
                vector<int> nxt;
                for (int i = jr; i < n; i ++) {
                        nxt.push_back(a[i]);
                }
                for (int i = jl; i < jr; i ++) {
                        nxt.push_back(a[i]);
                }
                for (int i = il; i < ir; i ++) {
                        nxt.push_back(a[i]);
                }
                for (int i = 0; i < il; i ++) {
                        nxt.push_back(a[i]);
                }
                vector<int> ope;
                if (il) ope.push_back(il);
                if (ir - il) ope.push_back(ir - il);
                if (jr - jl) ope.push_back(jr - jl);
                if (n - jr) ope.push_back(n - jr);
                ans.push_back(ope);
                swap(a, nxt);
        }
        assert(ans.size() <= n);
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
                cout << ans[i].size() << " ";
                rep(j, ans[i].size()) {
                        cout << ans[i][j] << " \n"[j + 1 == ans[i].size()];
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
