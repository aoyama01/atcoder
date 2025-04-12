// https://atcoder.jp/contests/abc396/tasks

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
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = false;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
            flag = true;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}
