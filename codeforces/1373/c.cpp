#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
int main() {
        int t;
        cin >> t;
        while (t --) {
                string s;
                cin >> s;
                int n = s.size();
                vector<int> dep(n + 1, -1);
                int cur = 0;
                rep(i, n) {
                        if (s[i] == '-') {
                                if (0 <= cur && cur < n + 1 && dep[cur] == -1) {
                                        dep[cur] = i;
                                }
                                cur ++;
                        } else {
                                cur --;
                        }
                }
                long long ans = n;
                rep(i, n + 1) {
                        ans += dep[i] + 1;
                }
                cout << ans << "\n";
        }
        return 0;
}