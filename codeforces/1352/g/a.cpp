#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n;
        cin >> n;
        if (n <= 3) {
                cout << -1 << '\n';
                return;
        }
        deque<int> ans;
        ans.push_back(3);
        ans.push_back(1);
        ans.push_back(4);
        ans.push_back(2);
        for (int i = 5; i <= n; i ++) {
                if (i & 1) {
                        ans.push_front(i);
                } else {
                        ans.push_back(i);
                }
        }
        while (ans.size()) {
                cout << ans.front() << " ";
                ans.pop_front();
        }
        cout << '\n';
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
