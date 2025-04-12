#include <bits/stdc++.h>

#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1 << 29;
const long long INF_LL = 1LL << 60;
template <class T>
void chmin(T& a, T b) {
    if (a > b) a = b;
}
template <class T>
void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main() {
    string s, t;
    cin >> s >> t;

    int i = 0;
    while (i < s.size() || i < t.size()) {
        // cout << s[i] << "と" << t[i] << "を比較" << endl;
        if (s[i] != t[i]) {
            // cout << s[i] << "と" << t[i] << "が不一致" << endl;
            cout << i+1 << endl;
            return 0;
        }
        i++;
    }

    cout << 0 << endl;
    
    return 0;
}
