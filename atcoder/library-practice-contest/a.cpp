#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
using namespace atcoder;

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int n, q;
        cin >> n >> q;
        dsu uf(n);
        rep(i, q) {
                int t, u, v;
                cin >> t >> u >> v;
                if (t) {
                        cout << uf.same(u, v) << '\n';
                } else {
                        uf.merge(u, v);
                }
        }
        return 0;
}
