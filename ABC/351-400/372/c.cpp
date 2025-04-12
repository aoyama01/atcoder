// #include <bits/stdc++.h>

// #include <regex>
// using namespace std;
// #define ll long long
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// const int INF_INT = 1 << 29;
// const long long INF_LL = 1LL << 60;
// template <class T>
// void chmin(T& a, T b) {
//     if (a > b) a = b;
// }
// template <class T>
// void chmax(T& a, T b) {
//     if (a < b) a = b;
// }

// int main() {
//     ll n, q;
//     cin >> n >> q;
//     string s;
//     cin >> s;
//     ll x[q];
//     char c[q];
//     for (int i = 0; i < n; i++) cin >> x[i] >> c[i];

//     for (int i = 0; i < q; i++) {
//         s[x[i] - 1] = c[i];
//         cout << s << " ";
//         int count = 0;
//         string target = "ABC";
//         size_t pos = s.find(target);  // 最初の "ABC" の位置を検索

//         while (pos != std::string::npos) {  // 見つかった場合
//             count++;
//             pos = s.find(target, pos + 1);  // 次の "ABC" を探す
//         }

//         cout << count << endl;
//     }

//     return 0;
// }

// ↓↓↓ ChatGPTに計算量を改善してもらった
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int countABC(const string &s, int pos) {
    // 部分文字列 "ABC" を pos 付近でチェック
    if (pos < 0 || pos + 2 >= s.size()) return 0;
    return s.substr(pos, 3) == "ABC" ? 1 : 0;
}

int main() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll x[q];
    char c[q];
    for (int i = 0; i < q; i++) cin >> x[i] >> c[i];

    // 初期状態での "ABC" の個数を計算
    int totalCount = 0;
    for (int i = 0; i + 2 < n; i++) {
        totalCount += countABC(s, i);
    }

    // 各クエリに対する処理
    for (int i = 0; i < q; i++) {
        int pos = x[i] - 1;

        // 変更前の位置周辺の "ABC" を除去
        for (int j = pos - 2; j <= pos; j++) {
            totalCount -= countABC(s, j);
        }

        // 文字列を更新
        s[pos] = c[i];

        // 変更後の位置周辺の "ABC" を追加
        for (int j = pos - 2; j <= pos; j++) {
            totalCount += countABC(s, j);
        }

        // 出力
        cout << totalCount << endl;
    }

    return 0;
}
