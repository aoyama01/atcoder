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

// 最小差を計算する関数
int findMinDifference(const vector<int>& arr) {
    int n = arr.size();
    int sumTotal = accumulate(arr.begin(), arr.end(), 0);  // 配列の合計値を求める
    int halfSum = sumTotal / 2;

    // DPテーブル
    vector<vector<bool>> dp(n + 1, vector<bool>(halfSum + 1, false));

    // 初期化：dp[0][0]は常にtrue
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // DPで部分和を計算
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= halfSum; ++j) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // 合計が半分に近い最大の部分和を探す
    int sumClosestToHalf = 0;
    for (int j = halfSum; j >= 0; --j) {
        if (dp[n][j]) {
            sumClosestToHalf = j;
            break;
        }
    }

    // グループ間の合計の差を返す
    return abs(sumTotal - 2 * sumClosestToHalf);
}

int main() {
    vector<int> arr = {1, 6, 11, 5};  // 配列のサンプル

    int minDifference = findMinDifference(arr);

    cout << "最小の差: " << minDifference << endl;

    return 0;
}