#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
using ll = long long;

void solve() {
        /*
        set<ll> st;
        int c = 1000;
        while (c --) {
                ll aa = -1, bb = -1, cc = -1;
                for (ll a = 1; ; a ++) {
                        if (st.count(a) == 0) {
                                aa = a;
                                break;
                        }
                }
                for (ll b = aa + 1; ; b ++) {
                        if (st.count(b) == 0) {
                                for (ll c = b + 1; c <= b + 2000; c ++) {
                                        if (st.count(c) == 0) {
                                                if ((aa ^ b ^ c) == 0) {
                                                        bb = b;
                                                        cc = c;
                                                        goto end;
                                                }
                                        }
                                }
                        }
                }
                end:;
                cerr << aa << " " << bb << " " << cc << '\n';
                st.insert(aa);
                st.insert(bb);
                st.insert(cc);
        }
        */
        ll n;
        cin >> n;
        ll b = 1;
        while (n > b) {
                b *= 2;
        }
        ll a = b / 2;
        cout << a;
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
