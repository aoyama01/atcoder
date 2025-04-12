#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vec<vec<char>> a(h, vec<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    // グリッドの確認
    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }

    // カウンタ
    ll cnt = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // 初期状態
            ll H = i, W = j;
            // 初手で海なら次の初期状態へ
            if (a[H][W] == '#') continue;

            for (int k = 0; k < n; k++) {
                switch (t[k])
                {
                case 'L':
                    W--;
                    break;
                case 'R':
                    W++;
                    break;
                case 'U':
                    H--;
                    break;
                case 'D':
                    H++;
                    break;
                
                default:
                    break;
                }
                if (a[H][W] == '#') break;
            }

            // break処理でループ終わったときはカウントしたらだめ
            if (a[H][W] == '#') continue;

            // breakせずにforループが完了したらカウント
            cnt++;
        }
    }

    cout << cnt << endl;
    
    return 0;
}
