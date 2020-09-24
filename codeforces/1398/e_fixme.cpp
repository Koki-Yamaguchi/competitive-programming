#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

/*
sum = 総和
sum_l = l の総和
sum_top(x) = 上位 x 個の和 (x = l, l - 1) -> A
f_max = f の max (sum_top(x) がわかるなら sum_l_f(1) みたいなのをとれるだろうとは思う）

top_all_l = 上位 l 個が全部 l か？ = (sum_l == sum_top(l))

ans = top_all_l ? sum + sum_top(l) :
                  sum + sum_top(l - 1) + f_max
*/

void solve() {
        int q;
        cin >> q;
        while (q --) {
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
