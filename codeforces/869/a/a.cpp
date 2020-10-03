#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        set<int> st;
        rep(i, n) {
                cin >> a[i];
                st.insert(a[i]);
        }
        rep(i, n) {
                cin >> b[i];
                st.insert(b[i]);
        }
        int cnt = 0;
        rep(i, n) {
                rep(j, n) {
                        int p = a[i] ^ b[j];
                        cnt += (st.count(p) > 0);
                }
        }
        cout << (cnt & 1 ? "Koyomi" : "Karen") << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        // cin >> t;
        t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
