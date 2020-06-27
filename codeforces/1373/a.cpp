#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
int main() {
        int t;
        cin >> t;
        while (t --) {
                int a, b, c;
                cin >> a >> b >> c;
                int ansa, ansb;
                long long d = (long long) a * b;
                if (a >= c) {
                        ansa = -1;
                        ansb = 2;
                } else if (d <= c) {
                        ansa = 1;
                        ansb = -1;
                } else {
                        ansa = 1;
                        ansb = b;
                }
                cout << ansa << " " << ansb << endl;
        }
        return 0;
}