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
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll m; cin >> m;
    ll b[m];
    for (int i = 0; i < m; i++) cin >> b[i];
    ll l; cin >> l;
    ll c[l];
    for (int i = 0; i < l; i++) cin >> c[i];

    set<ll> s;
    for (ll A : a) {
        for (ll B : b) {
            for (ll C : c) {
                s.insert(A + B + C);
            }
        }
    }

    ll q; cin >> q;
    ll x[q];
    for (int i = 0; i < q; i++) {
        ll x; cin >> x;
        if (s.find(x) != s.end()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
