#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;

int main() {
    ll n, m; cin >> n >> m;
    ll a[m];
    for (int i = 0; i < m; i++) cin >> a[i];
    ll x[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x[i][j];
        }
    }
    bool flag = true;

    // それぞれの栄養素について
    for (int i = 0; i < m; i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            sum += x[j][i];
        }
        // 基準を満たしているか
        if (sum < a[i]) flag = false;
    }
    
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
