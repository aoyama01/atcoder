#include <bits/stdc++.h>
#include <regex>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1 << 29;
const long long INF_LL = 1LL << 60;

template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    ll n;
    cin >> n;

    // 正しい2次元ベクトルの初期化
    vector<vector<ll>> a(n, vector<ll>(n));

    ll index = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < index; j++) {
            cin >> a[i][j];
        }
        index++;
    }

    // index = 1;  // インデックスをリセット
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < index; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    //     index++;
    // }
    
    ll element = 1;
    for (int i = 0; i < n; i++) {
      // 最初は1と1
      // 2回目移行はaと2, 3, 4,...
      if (element-1 >= i) element = a[element-1][i];
      else element = a[i][element-1];
      // cout << element << endl;
    }
    
    cout << element << endl;

    return 0;
}
