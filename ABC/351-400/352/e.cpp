#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

// ↓これ読んだみただけ
// https://algo-method.com/tasks/954/editorial
int main() {
    ll n, m; cin >> n >> m;
    ll k[m], c[m];
    vector<vector<ll>> a(m, n);
    for (int i = 0; i < m; i++) {
        cin >> k[i] >> c[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> a[i][j];
        }
    }
    
    return 0;
}
