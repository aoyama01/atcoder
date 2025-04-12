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
    ll n; cin >> n;
    ll h[n];
    for (int i = 0; i < n; i++) cin >> h[i];

    int flag = -1;
    for (int i = 0; i < n; i++) {
        if (h[i] > h[0]) {
            flag = i+1;
            break;
        }
    }

    cout << flag << endl;
    
    return 0;
}
