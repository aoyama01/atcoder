#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

#define MAX_N 7
#define MAX_H 10
#define MAX_W 10

int n, h, w; // タイルの枚数、マス目の行数、マス目の列数
int a[MAX_N]; // タイルの高さ
int b[MAX_N]; // タイルの幅
int c[MAX_H][MAX_W]; // タイルの配置を表す二次元配列
bool ans; // 解が存在するかどうかを示すフラグ

// タイルを置く再帰関数
void solve(int unused, int curi, int curj) {
    bool can; // タイルを置けるかどうかを示すフラグ
    // タイルを置ける場所を探す
    // 0以上なら置けないので，-1で初期化されたままの置ける場所を探す
    while(c[curi][curj] >= 0) {
        curj++;
        if(curj >= w) {
            curi++;
            curj = 0;
        }
        if(curi >= h) break;
    }
    // 全てのマスがタイルで覆われた場合、解を発見したので終了
    if(curi >= h) {
        ans = true;
        return;
    }
    // 未使用のタイルを順番に試す
    rep(i, n) {
        if(unused & (1 << i)) {
            can = true;
            // タイルを配置する
            rep(ii, a[i]) {
                rep(jj, b[i]) {
                    if(((curi + ii) < h) && ((curj + jj) < w)) {
                        // マス目の範囲内に収まる場合
                        if(c[curi + ii][curj + jj] < 0) c[curi + ii][curj + jj] = i;
                        else can = false; // タイルが重なる場合は置けない
                    } else can = false; // マス目からはみ出る場合は置けない
                }
            }
            // タイルを配置できる場合は再帰的に探索
            if(can) solve(unused ^ (1 << i), curi, curj);
            // タイルの配置を戻す
            rep(ii, a[i]) {
                rep(jj, b[i]) {
                    if(((curi + ii) < h) && ((curj + jj) < w)) {
                        if(c[curi + ii][curj + jj] == i) c[curi + ii][curj + jj] = -1;
                    }
                }
            }
            // タイルの幅と高さが異なる場合の配置も試す
            if(a[i] != b[i]) {
                can = true;
                rep(ii, b[i]) {
                    rep(jj, a[i]) {
                        if(((curi + ii) < h) && ((curj + jj) < w)) {
                            if(c[curi + ii][curj + jj] < 0) c[curi + ii][curj + jj] = i;
                            else can = false;
                        } else can = false;
                    }
                }
                if(can) solve(unused ^ (1 << i), curi, curj);
                rep(ii, b[i]) {
                    rep(jj, a[i]) {
                        if(((curi + ii) < h) && ((curj + jj) < w)) {
                            if(c[curi + ii][curj + jj] == i) c[curi + ii][curj + jj] = -1;
                        }
                    }
                }
            }
        }
    }
    return;
}

int main(void) {
    // 入力
    cin >> n >> h >> w;
    rep(i, n) cin >> a[i] >> b[i];
    // タイルの配置を初期化
    rep(i, h) rep(j, w) c[i][j] = -1;
    ans = false;
    // タイルを置く再帰関数を呼び出し
    solve((1 << n) - 1, 0, 0);
    // 結果を出力
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
