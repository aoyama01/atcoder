#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    ll r[q], c[q];
    for (ll i = 0; i < q; i++) cin >> r[i] >> c[i];

    int g[h][w];
    memset(g, 0, sizeof(g)); // memsetを使って2次元配列を0で初期化

    ll count = 0;
    // q個のクエリの処理
    for (ll i = 0; i < q; i++) {
        // 壁が(r[q], c[q])に存在する場合
        if (g[r[i]][c[i]] == 0) {
            g[r[i]][c[i]] = -1; // 壁を破壊
            count++;
        }
        // 壁が(r[q], c[q])に存在しない場合
        else {
            // まず上を見て，始めに現れた壁を破壊
            bool exploded = false;
            ll a = r[i], b = c[i];
            while(a >= 0 && exploded == false) {
                if (g[a][b] == 0) {
                    g[a][b] = -1; // 壁を破壊
                    count++;
                    exploded = true;
                };
                a--;
            }
            // 次に下
            a = r[i];
            b = c[i];
            exploded = false;
            while(a <=h  && exploded == false) {
                if (g[a][b] == 0) {
                    g[a][b] = -1; // 壁を破壊
                    count++;
                    exploded = true;
                };
                a++;
            }
            // 次に左
            a = r[i];
            b = c[i];
            exploded = false;
            while(b >= 0 && exploded == false) {
                if (g[a][b] == 0) {
                    g[a][b] = -1; // 壁を破壊
                    count++;
                    exploded = true;
                };
                b--;
            }
            // 最後に右
            a = r[i];
            b = c[i];
            exploded = false;
            while(b <= w && exploded == false) {
                if (g[a][b] == 0) {
                    g[a][b] = -1; // 壁を破壊
                    count++;
                    exploded = true;
                };
                b++;
            }
        }
    }

    cout << h * w - count << endl;


    return 0;
}
