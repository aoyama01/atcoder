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
    // string s; cin >> s;

    // int cnt = 0;
    // for (int i = 0; i < s.size(); i++) {
    //     if (s[i] == '|') cnt++;
    //     if (cnt == 0 || cnt == 2) {
    //         if (s[i] != '|') cout << s[i];
    //     }
    // }
    // cout << endl;

    // 別解(<regex>クラスが必要)
    string s; cin >> s;

    regex pattern("\\|.*\\|");
    cout << regex_replace(s, pattern, "") << endl;

    return 0;
}
