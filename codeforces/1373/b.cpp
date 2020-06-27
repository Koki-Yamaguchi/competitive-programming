#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
int main() {
        int n;
        cin >> n;
        rep(i, n) {
                string s;
                cin >> s;
                int a = 0, b = 0;
                rep(i, s.size()) {
                        a += s[i] == '1';
                        b += s[i] == '0';
                }
                int c = min(a, b);
                puts(c & 1 ? "DA" : "NET");
        }
        return 0;
}