#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

vector<ll> memo;

ll lucas(int n) {
    if (n == 0) return memo[0] = 2;
    if (n == 1) return memo[1] = 1;

    if (memo[n] != -1) return memo[n];

    return memo[n] = lucas(n-1) + lucas(n-2);
}

int main() {
    ll n; cin >> n;
    memo.assign(87, -1);

    cout << lucas(n) << endl;
    
    return 0;
}
