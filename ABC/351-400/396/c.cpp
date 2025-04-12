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
    ll n, m;
    cin >> n >> m;
    ll b[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll w[m];
    for (int i = 0; i < m; i++) cin >> w[i];

    // 降順にソート
    sort(b, b + n, greater<ll>());
    sort(w, w + m, greater<ll>());

    /**
     * 1. B >= 0 なら B を選ぶ．同時に，W >= 0 なら W を選ぶ．
     * 2. B < 0 かつ b + W >= 0 なら B と W を選ぶ．
     * 3. W > 0 または B >= W なら B と W を選ぶ．
     */

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        bool done_sum = false;
        if (b[i] >= 0) {
            sum += b[i];
            done_sum = true;
            if (i < m && w[i] >= 0) {  // W の範囲外にアクセスしないようにする
                sum += w[i];
                done_sum = true;
            }
        } else if (i < m &&
                   b[i] + w[i] >= 0) {  // W の範囲外にアクセスしないようにする
            sum += b[i] + w[i];
            done_sum = true;
        }
        if (!done_sum) {
            break;
        }
    }

    cout << sum << endl;

    return 0;
}
