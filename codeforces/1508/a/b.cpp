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

bool is_sub(const string &s, const string &sub) {
        int subp = 0;
        rep(i, s.size()) {
                if (s[i] == sub[subp]) {
                        subp ++;
                        if (subp == sub.size()) {
                                break;
                        }
                }
        }
        return subp == sub.size();
}

void solve() {
        int n;
        cin >> n;
        vector<string> s(3);
        rep(i, 3) {
                cin >> s[i];
        }

        rep(i, 3) {
                string subf = s[i].substr(0, n);
                string subb = s[i].substr(n, n);
                rep(j, 3) if (i != j) {
                        if (is_sub(s[j], subf)) {
                                cout << s[j] << subb << '\n';
                                return;
                        }
                        if (is_sub(s[j], subb)) {
                                cout << subf << s[j] << '\n';
                                return;
                        }
                }
        }

        vector<int> cnt_all(3);
        vector<bool> use_one(2 * n);
        rep(i, 2 * n) {
                vector<int> cnt(2);
                rep(j, 3) {
                        cnt[s[j][i] - '0'] ++;
                }
                use_one[i] = cnt[0] < cnt[1];
                int use_cnt = 0;
                if (cnt[0] > cnt[1]) {
                        rep(j, 3) {
                                if (s[j][i] == '0' && use_cnt <= 1) {
                                        cnt_all[j] ++;
                                        use_cnt ++;
                                }
                        }
                } else {
                        rep(j, 3) {
                                if (s[j][i] == '1' && use_cnt <= 1) {
                                        cnt_all[j] ++;
                                        use_cnt ++;
                                }
                        }
                }
        }
        assert(cnt_all[0] + cnt_all[1] + cnt_all[2] == 2 * 2 * n);
        vector<int> idx(3);
        rep(i, 3) idx[i] = i;
        sort(all(idx), [&](auto a, auto b) {
                return cnt_all[a] > cnt_all[b];
        });
        int p = idx[0];
        int q = idx[1];
        // assert(2 * n - cnt_all[p] - cnt_all[q] <= n);
        string ans;
        rep(i, 2 * n) {
                if (s[p][i] == s[q][i]) {
                        ans.push_back(s[p][i]);
                } else {
                        ans.push_back(s[p][i]);
                        ans.push_back(s[q][i]);
                }
        }
        cout << ans << '\n';
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
