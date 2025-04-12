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
    ll n, m, k; cin >> n;
    ll c[m];
    string r[m];
    vector<vector<ll>> a(m, 15);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        for (int j = 0; j < c[i]; j++) cin >> a[i][j];
        cin >> r[i];
    };

    return 0;
}
