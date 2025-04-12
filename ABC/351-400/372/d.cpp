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

int main() {
    ll n;
    cin >> n;
    ll h[n];
    for (int i = 0; i < n; i++) cin >> h[i];

    // 「ビル i とビル j の間にビル j より高いビルが存在しない」
    // を満たす j の個数を求める
    for (int i = 0; i < n; i++) {
        ll count = 0;
        ll h_max = 0;
        for (int j = i + 1; j < n; j++) {
            if (h[j] > h_max) {
                h_max = h[j];
                count++;
            }
        }
        // 出力
        if (i == n - 1)
            cout << count << endl;
        else
            cout << count << " ";
    }

    return 0;
}
