#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<vector<int>>> ts(n, vector<vector<int>> (2, vector<int> (2)));
        rep(i, n) {
                cin >> ts[i][0][0];
                cin >> ts[i][0][1];
                cin >> ts[i][1][0];
                cin >> ts[i][1][1];
        }
        if (m % 2) {
                cout << "NO" << '\n';
                return;
        }
        rep(i, n) {
                if (ts[i][0][1] == ts[i][1][0]) {
                        cout << "YES" << '\n';
                        return;
                } 
        }
        cout << "NO" << '\n';
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
