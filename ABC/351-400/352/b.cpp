#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    string s, t;
    cin >> s >> t;
    vector<ll> index;
    ll pos = 0;
    for (int i = 0; i < s.size(); i++) {
        // sのi文字目がtの何文字目にあるのか検索
        pos = t.find(s[i], pos) + 1;
        index.push_back(pos);
    }

    for (int i = 0; i < index.size(); i++) {
        if (i != index.size() - 1) cout << index[i] << " ";
        else cout << index[i] << endl;
    }
    
    return 0;
}
