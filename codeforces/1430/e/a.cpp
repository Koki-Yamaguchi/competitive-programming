#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

//1-origin
template <typename T>
struct FenwickTree {
        vector<T> data;
        FenwickTree(int n) : data(n + 1, 0) {}
        //data[i] += x
        void add(int i, T x){
                while (i <= (int)data.size()) {
                        data[i] += x;
                        i += i & -i;
                }
        }
        //[1, i)
        T sum(int i){
                T res = 0;
                while (i > 0) {
                        res += data[i];
                        i -= i & -i;
                }
                return res;
        }
        //[l, r)
        T sum(int l, int r) { return sum(r) - sum(l); }
};
long long InversionNumber(const vector<int> &a) {
        FenwickTree<long long> ft(300030);
        long long res = 0;
        for (int i = 0; i < a.size(); i ++) {
                res += i - ft.sum(a[i]);
                ft.add(a[i], 1);
        }
        return res;
}

void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<pair<char, int>, int> z;
        map<int, int> cnt;
        int k = 1;
        rep(i, n) {
                if (z.count(make_pair(s[i], cnt[s[i]])) == 0) z[make_pair(s[i], cnt[s[i]])] = k ++;
                cnt[s[i]] ++;
        }
        reverse(s.begin(), s.end());
        vector<int> p;
        cnt.clear();
        rep(i, n) {
                p.push_back(z[make_pair(s[i], cnt[s[i]])]);
                cnt[s[i]] ++;
        }
        long long ans = InversionNumber(p);
        cout << ans << '\n';
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
