#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
int main() {
        int t;
        scanf("%d", &t);
        while (t --) {
                int n;
                scanf("%d", &n);
                long long acca = 0, accb = 0, mia = 0, mib = 0, da = 0, db = 0, ans = 0;
                int cura = 0, curb = 0;
                rep(i, n) {
                        int a;
                        scanf("%d", &a);
                        if (i & 1) {
                                cura = a - cura;
                                curb = a;
 
                                acca += cura;
                                da = max(da, acca - mia);
                                mia = min(mia, acca);
                        } else {
                                curb = curb - a;
                                cura = a;
 
                                if (i) {
                                        accb += curb;
                                        db = max(db, accb - mib);
                                        mib = min(mib, accb);
                                }
 
                                ans += cura;
                        }
                }
                if (max(da, db) > 0) ans += max(da, db);
                printf("%lld\n", ans);
        }
        return 0;
}
