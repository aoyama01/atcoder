#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    // 入力
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    ll W = 0;
    for (int i = 0; i < N; i++) {
        W += a[i];
    }

    // DP
    // 最初の i 個の整数の中からいくつか選んだ総和が j にできるかどうかを表すブール値 (true / false)
    vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            // a[i] を選ばない場合
            if (dp[i][j]) dp[i+1][j] = true;

            // a[i] を選ぶ場合
            if (j >= a[i] && dp[i][j-a[i]]) dp[i+1][j] = true;
        }
    }

    ll cnt = 0;
    for (int j = 0; j <= W; j++) {
        // 整数jを作れるか判定
        if (dp[N][j]) cnt++;
    }

    // 答え
    cout << cnt << endl;

    return 0;
}
