#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    long long n;
    cin >> n;
    // 入力に合わせて配列のサイズを変えたいので要素数は指定しない
    vector<long long> a;

    // 始めは整数nのみが書かれている
    a.push_back(n);

    // 始めの支払金額は0円
    long long sum = 0;
    
    // ループ開始 (ループ終了の条件は？←配列のサイズが0になったら)
    while (a.size() >= 1) {
            
        // 配列aの末尾の値を取得しxとする．aからは末尾の値を削除
        long long x;
        x = a.at(a.size()-1); // 末尾の要素を取得
        a.pop_back(); // 末尾の要素を削除

        // x==1のとき
        if (x == 1) {
            // 次のループへ
            continue;
        }

        // x>=2のとき
        if (x >= 2) {
            // 2個の整数を配列aに追加
            long long x_rd = x/2; // x/2を切り下げた値(暗黙の型変換)
            a.push_back(x_rd);
            long long x_ru = (x + 2 -1) / 2; // x/2を切り上げた値
            a.push_back(x_ru);
            // 支払金額にxを加算
            sum += x;
        }
    }
    // ループ終了

    // 支払金額の合計を表示
    cout << sum << endl;
    
    return 0;
}
