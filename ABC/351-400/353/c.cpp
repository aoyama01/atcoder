#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

// const ll MOD = 1e8;

// // xのn乗のMOD
// LL powMod(LL x, LL n) {
//   if (n == 0) return 1 % MOD;
//   LL val = powMod(x, n / 2);
//   val *= val;
//   if (n % 2 == 1) val *= x;
//   return val % MOD;
// }

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll sum = 0;

    ll ii = 0;
    while (5e7 < a[ii]) {
        sum += a[ii];
        ii++;
    }

    for (ll i = ii; i < n; i++) {
        for (ll j = i+1; j < n; j++) {
            ll res = (a[i] + a[j]) % (ll)1e8;
            // cout << a[i] + a[j] << " → 余り：" << res << endl;
            sum += res;
        }
    }

    cout << sum << endl;
    
    return 0;
}
