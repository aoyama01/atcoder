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

    if (s[0] != s[1]) {
        // 異なる文字は1文字目or2文字目
        if (s[0] == s[2]) cout << 2 << endl;
        else cout << 1 << endl;
    }
    else {
        // 異なる文字は3文字目以降
        for (int i = 0; i < s.size(); i++) {
            if (s[0] != s[i]) {
                cout << i+1 << endl;
                break;
            }
        }
    }
    
    return 0;
}
