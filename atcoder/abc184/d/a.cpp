#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p) {
        os << p.first << " " << p.second;
        return os;
}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	for (int i = 0; i < vec.size(); i ++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}

double f(int a, int b, int c, vector<vector<vector<double>>> &dp) {
        if (dp[a][b][c] != -1) {
                return dp[a][b][c];
        }
        if (a == 100 || b == 100 || c == 100) {
                return dp[a][b][c] = 0.0;
        }
        double res = 0;
        res += (double) a / (a + b + c) * (f(a + 1, b, c, dp) + 1);
        res += (double) b / (a + b + c) * (f(a, b + 1, c, dp) + 1);
        res += (double) c / (a + b + c) * (f(a, b, c + 1, dp) + 1);
        return dp[a][b][c] = res;
}

void solve() {
        int a, b, c;
        cin >> a >> b >> c;
        vector<vector<vector<double>>> dp(101, vector<vector<double>> (101, vector<double> (101, -1)));
        cout << fixed << setprecision(10) << f(a, b, c, dp) << '\n';
}

int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        // int t; cin >> t;
        int t = 1;
        while (t --) {
                solve();
        }
        return 0;
}
