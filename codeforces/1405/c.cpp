#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<int, char> to;
        rep(i, n) {
                if (s[i] == '?') continue;
                if (to.count(i % k)) {
                        if (to[i % k] != s[i]) {
                                cout << "NO" << '\n';
                                return;
                        }
                } else {
                        to[i % k] = s[i];
                }
        }
        rep(i, n) {
                s[i] = to[i % k];
        }
        // cerr << s << endl;
        int zc = 0, oc = 0, qc = 0;
        rep(i, k) {
                if (s[i] == '0') {
                        zc ++;
                } else if (s[i] == '1') {
                        oc ++;
                } else {
                        qc ++;
                }
        }
        int d = abs(zc - oc);
        /*
        cerr << "d = " << d << endl;
        cerr << "qc = " << qc << endl;
        */
        if (d <= qc) {
                cout << "YES" << '\n';
        } else {
                cout << "NO" << '\n';
        }
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t --) {
                solve();
        }
        return 0;
}
