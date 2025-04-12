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
    ll n, l, r; cin >> n >> l >> r;

    for (int i = 1; i < n+1; i++) {
        if (l <= i && i <= r) {
            if (i == n) cout << l + r - i << endl;
            else cout << l + r - i << " ";
        } else {
            if (i == n) cout << i << endl;
            else cout << i << " ";
        }
    };
    
    return 0;
}
