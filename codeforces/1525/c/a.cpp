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
        int n, m;
        cin >> n >> m;
        vector<int> x(n);
        rep(i, n) {
                cin >> x[i];
        }
        vector<char> dir(n);
        rep(i, n) {
                cin >> dir[i];
        }
        vector<pair<pair<int, char>, int>> xe, xo;
        rep(i, n) {
                if (x[i] & 1) {
                        xo.push_back({{x[i], dir[i]}, i});
                } else {
                        xe.push_back({{x[i], dir[i]}, i});
                }
        }
        sort(all(xo));
        sort(all(xe));
        vector<int> ans(n, -1);
        auto calc = [&](const vector<pair<pair<int, char>, int>> &v) {
                vector<pair<pair<int, int>, int>> right;
                vector<pair<pair<int, int>, int>> left;
                rep(i, v.size()) {
                        auto [rob, idx] = v[i];
                        auto [pos, dir] = rob;
                        if (dir == 'R') {
                                right.push_back(v[i]);
                        } else {
                                if (right.empty()) {
                                        left.push_back(v[i]);
                                } else {
                                        auto [prevrob, previdx] = right.back();
                                        auto [prevpos, _gomi] = prevrob;
                                        right.pop_back();
                                        assert((pos - prevpos) % 2 == 0);
                                        int t = (pos - prevpos) / 2;
                                        ans[idx] = t;
                                        ans[previdx] = t;
                                }
                        }
                }
                for (int i = 0; i + 1 < left.size(); i += 2) {
                        auto [rob, idx] = left[i];
                        auto [pos, _] = rob;         
                        auto [nxtrob, nxtidx] = left[i + 1];
                        auto [nxtpos, _gomi] = nxtrob;
                        int ttt = pos - 0 + nxtpos - 0;
                        assert(ttt % 2 == 0);
                        int t = ttt / 2;
                        ans[idx] = t;
                        ans[nxtidx] = t;
                }
                reverse(all(right));
                for (int i = 0; i + 1 < right.size(); i += 2) {
                        auto [rob, idx] = right[i];
                        auto [pos, _] = rob;         
                        auto [nxtrob, nxtidx] = right[i + 1];
                        auto [nxtpos, _gomi] = nxtrob;
                        int ttt = (m - pos) + (m - nxtpos);
                        assert(ttt % 2 == 0);
                        int t = ttt / 2;
                        ans[idx] = t;
                        ans[nxtidx] = t;
                }
                if (left.size() % 2 == 1 && right.size() % 2 == 1) {
                        auto [rob, idx] = left.back();
                        auto [pos, _] = rob;         
                        auto [nxtrob, nxtidx] = right.back();
                        auto [nxtpos, _gomi] = nxtrob;
                        int ttt = pos - 0 + (m - nxtpos) + m;
                        assert(ttt % 2 == 0);
                        int t = ttt / 2;
                        ans[idx] = t;
                        ans[nxtidx] = t;
                }
        };
        calc(xo);
        calc(xe);
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
