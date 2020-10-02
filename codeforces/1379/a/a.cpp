#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = "abacaba";
        cerr << endl;
        rep(i, n) {
                int c = 0;
                for (int j = i; j < i + t.size(); j ++) {
                        c += (s[j] == '?' || s[j] == t[j - i]);
                }
                if (c == t.size()) {
                        string ss = s;
                        cerr << "ss = " << ss << endl;
                        for (int j = i; j < i + t.size(); j ++) {
                                ss[j] = t[j - i];
                        }
                        cerr << "ss = " << ss << endl;
                        int app = 0;
                        rep(j, n) {
                                int c = 0;
                                for (int k = j; k < j + t.size(); k ++) {
                                        c += ss[k] == t[k - j];
                                }
                                if (c == t.size()) {
                                        app ++;
                                }
                        }
                        if (app == 1) {
                                cout << "Yes\n";
                                for (int j = 0; j < s.size(); j ++) {
                                        if (ss[j] == '?') {
                                                ss[j] = 'z';
                                        }
                                }
                                cout << ss << '\n';
                                return;
                        }
                }
        }
        cout << "No\n";
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
