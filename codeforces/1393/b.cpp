#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        map<int, int> cnt;
        int eight = 0, six = 0, four = 0, two = 0;
        rep(i, n) {
                int a;
                cin >> a;
                cnt[a] ++;
                if (cnt[a] == 2) {
                        two ++;
                }
                if (cnt[a] == 4) {
                        four ++;
                        two --;
                }
                if (cnt[a] == 6) {
                        six ++;
                        four --;
                }
                if (cnt[a] == 8) {
                        eight ++;
                        six --;
                }
        }
        int q;
        cin >> q;
        while (q --) {
                string sign;
                cin >> sign;
                int a;
                cin >> a;
                if (sign == "+") {
                        cnt[a] ++;
                        if (cnt[a] == 2) {
                                two ++;
                        }
                        if (cnt[a] == 4) {
                                four ++;
                                two --;
                        }
                        if (cnt[a] == 6) {
                                six ++;
                                four --;
                        }
                        if (cnt[a] == 8) {
                                eight ++;
                                six --;
                        }
                } else {
                        if (cnt[a] == 2) {
                                two --;
                        }
                        if (cnt[a] == 4) {
                                four --;
                                two ++;
                        }
                        if (cnt[a] == 6) {
                                six --;
                                four ++;
                        }
                        if (cnt[a] == 8) {
                                eight --;
                                six ++;
                        }
                        cnt[a] --;
                }
                if (eight >= 1 ||
                   (six >= 2) ||
                   (six >= 1 && four >= 1) ||
                   (six >= 1 && two >= 1) ||
                   (four >= 2) ||
                   (four >= 1 && two >= 2)) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }
        }
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
