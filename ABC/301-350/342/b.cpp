#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    ll n; cin >> n;
    ll p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    ll q; cin >> q;
    ll a[n], b[n];
    // for (int i = 0; i < q; i++) {
    //     cin >> a[i] >> b[i];
    // }

    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
        ll A = 0, B = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == p[j]) A == j;
            if (b[i] == p[j]) B == j;
        }
        if (A < B) cout << a[i] << endl;
        else cout << b[i] << endl;
    }
    
    return 0;
}
