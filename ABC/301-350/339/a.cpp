#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define vec vector
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    string s;
    cin >> s;
    
    int loc = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') loc = i;
    }
    
    for (int i = loc + 1; i < s.size(); i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}
