#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

void proceed(ll h, ll w, ll &x, ll &y, ll direc) {
    switch (direc)
    {

        //  配列における座標の考えかたに注意．xとyを逆に考えてしまってた

    case 0: // 上を向いているとき
        x = (x - 1 + h) % h;
        break;
    case 1:
        y = (y + 1) % w;
        break;
    case 2:
        x = (x + 1) % h;
        break;
    case 3:
        y = (y - 1 + w) % w;
        break;
    default:
        break;
    }
    return;
}

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    vec<vec<char>> a(h, vec<char>(w, '.'));

    // 初期状態
    ll x = 0, y = 0;
    ll direc = 0; // 上右下左を0,1,2,3と対応付ける

    for (int i = 0; i < n; i++) {
        // 現在いるマスが白で塗られている場合
        if (a[x][y] == '.') {
            a[x][y] = '#';
            // 時計回りに90度回転
            direc = (direc + 1) % 4;
            // 向いている方向に1マス進む←この関数ほしいかも
            proceed(h, w, x, y, direc);
        }

        // 現在いるマスが黒で塗られている場合
        else { // ここがifだと，1回の操作のはずが2回になっちゃうことがある
            a[x][y] = '.';
            // 反時計回りに90度回転
            direc = (direc - 1 + 4) % 4;
            // 向いている方向に1マス進む←この関数ほしいかも
            proceed(h, w, x, y, direc);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
