#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    string s; cin >> s;

    bool a = true;
    // for (auto it = s.begin() + 1; it != s.end() - 1; ++it) {
    //     if (*it != '=') a = false;
    // }

    // if (*s.begin() == '<' && *(s.end()-1) == '>' && a) {
    //     cout << "Yes" << endl;
    // }
    // else {
    //     cout << "No" << endl;
    // }

    // 条件式を分けたほうが見やすいかも
    if (s[0] != '<') a = false;

    int n = s.size();
    if (s[n-1] != '>') a = false;

    for (int i = 1; i < n-1; i++) { // i の範囲に注意
        if (s[i] != '=') a = false;
    }

    if (a) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
