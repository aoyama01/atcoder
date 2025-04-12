#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

bool isPalindrome(ll x) {
    ll digit = to_string(x).length();
    for (int i = 0; i < digit / 2; i++) {
        if (to_string(x).at(i) != to_string(x).at(digit - i - 1)) {
            return false;
        }
    }
    return true;
};

int main() {
    ll n; cin >> n;

    ll res = 0;
    ll x = 1;
    while (pow(x, 3) <= n) {
        if (isPalindrome(pow(x, 3))) res = pow(x, 3);
        x++;
    }

    cout << res << endl;
    
    return 0;
}
