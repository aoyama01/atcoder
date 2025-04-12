#include <iostream>
#include <map>
using namespace std;

// 連想配列を利用したメモ化再帰によって高速化

// 連想配列を定義
map<long long, long long> m;
// 再帰関数を定義
long long f(long long N) {
    // ベースケース
    if (N == 1) return 0;
    // メモが見つかった場合
    if (m.count(N)) return m[N];
        // map コンテナはキーの重複を許さないため、
        // この関数は実際には要素が見つかったときに 1 を、
        // そうでないときに 0 を返す。
        // https://cpprefjp.github.io/reference/map/map/count.html
    
    // 答えをメモ化しながら再帰呼び出し
    return m[N] = f(N / 2) + f((N + 1) / 2) + N;
}

int main() {
    long long N;
    cin >> N;
    cout << f(N) << endl;
}
