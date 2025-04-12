#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

// 「データ構造とアルゴリズム」code 5.7 と同じ

int main() {
    // 入力
    int N;
    ll W;
    cin >> N >> W;
    vector<ll> weight(N), value(N);
    for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

    // DP テーブル定義
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));

    // DP ループ
    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {

            // i 番目の品物を選ぶ場合
            if (w - weight[i] >= 0) {
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }

            // i 番目の品物を選ばない場合
            chmax(dp[i + 1][w], dp[i][w]);
        }
    }

    // 最適値の出力
    cout << dp[N][W] << endl;
}
