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

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0;
        if (s.substr(0, 1) == "2") {
                a ++;
                if (s.substr(0, 2) == "20") {
                        a ++;
                        if (s.substr(0, 3) == "202") {
                                a ++;
                                if (s.substr(0, 4) == "2020") {
                                        cout << "YES\n";
                                        return;
                                }
                        }
                }
        }
        reverse(all(s));
        int b = 0;
        if (s.substr(0, 1) == "0") {
                b ++;
                if (s.substr(0, 2) == "02") {
                        b ++;
                        if (s.substr(0, 3) == "020") {
                                b ++;
                                if (s.substr(0, 4) == "0202") {
                                        cout << "YES\n";
                                        return;
                                }
                        }
                }
        }
        if (a + b >= 4) {
                cout << "YES\n";
                return;
        }
        cout << "NO\n";
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
