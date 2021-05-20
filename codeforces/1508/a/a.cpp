#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define dump(x) cerr << #x << " = " << x << '\n';
using ll = long long;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.first << " " << p.second; return os; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec) { for (int i = 0; i < vec.size(); i ++) { os << vec[i] << (i + 1 == vec.size() ? "" : " "); } return os; }
template<typename T> ostream& operator << (ostream& os, const set<T> &p) { os << "{"; for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << *it; } os << "}"; return os; }
template<typename T, typename U> ostream& operator << (ostream& os, const map<T, U> &p) { for (auto it = p.begin(); it != p.end(); it ++) { if (it != p.begin()) { os << ", "; } os << "{" << (*it).first << ": " << (*it).second << "}"; } return os; }
template<typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }

void solve() {
        int n;
        cin >> n;
        vector<string> s(3);
        rep(i, 3) {
                cin >> s[i];
        }
        auto calc = [&](char x) {
                char y = (x == '1' ? '0' : '1');
                vector<int> xcnt(3);
                rep(i, 3) {
                        rep(j, 2 * n) {
                                xcnt[i] += (s[i][j] == x);
                        }
                }
                vector<int> idx(3); rep(i, 3) idx[i] = i;
                sort(all(idx), [&](auto a, auto b) {
                        return xcnt[a] > xcnt[b];
                });
                int p = idx[0];
                int q = idx[1];
                if (xcnt[p] >= n && xcnt[q] >= n) {
                        string ans;
                        int pp = 0, qp = 0;
                        while (true) {
                                if (s[p][pp] == x) {
                                        while (qp < 2 * n && s[q][qp] != x) {
                                                ans.push_back(y);
                                                qp ++;
                                        }
                                        ans.push_back(x);
                                        pp ++;
                                        qp ++;
                                } else {
                                        ans.push_back(y);
                                        pp ++;
                                }
                                if (pp >= 2 * n) {
                                        break;
                                }
                        }
                        assert(ans.size() <= 3 * n);
                        cout << ans << '\n';
                        return true;
                } else {
                        return false;
                }
        };
        bool ok = (calc('0') || calc('1'));
        assert(ok);
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
