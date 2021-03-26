#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

long long get(string s) {
        long long res = 0;
        long long b = 1;
        for (int i = s.size() - 1; i >= 0; i --) {
                res += (s[i] - '0') * b;
                b *= 2;
        }
        return res;
}

string rev(long long a, int m) {
        string s = bitset<61>(a).to_string();
        string res;
        for (int i = (int) s.size() - 1; i >= s.size() - m; i --) {
                res += s[i];
        }
        reverse(res.begin(), res.end());
        return res;
}

void solve() {
        int n, m;
        cin >> n >> m;
        long long mid = (pow(2, m) - 1) / 2;
        vector<long long> mids;
        for (long long i = max(0ll, mid - 105); i <= min(mid + 105, (long long) pow(2, m) - 1); i ++) {
                mids.push_back(i);
        }
        int left = 0, right = 0;
        vector<long long> tmp;
        rep(i, n) {
                string s;
                cin >> s;
                long long num = get(s);
                if (num < mids[0]) {
                        left ++;
                } else if (num > mids.back()) {
                        right ++;
                } else {
                        for (auto mid: mids) {
                                if (mid != num) {
                                        tmp.push_back(mid);
                                }
                        }
                        swap(tmp, mids);
                        tmp.clear();
                }
        }
        int d = abs(right - left);
        if (left < right) {
                reverse(mids.begin(), mids.end());
                while (d --) {
                        mids.push_back(-1);
                }
                reverse(mids.begin(), mids.end());
        } else {
                while (d --) {
                        mids.push_back(-1);
                }
        }
        cout << rev(mids[((int) mids.size() - 1) / 2], m) << '\n';
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
