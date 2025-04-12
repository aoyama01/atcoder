#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 20000000;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    double b;
    cin >> b;

    // A^A の計算 (テスト用)
    // long long sum = 1;
    // for (int i = 0; i < 15; i++) sum *= 15;
    // cout << sum << endl;

    for (double a = 1; a <= 15; a++) {
        long long x = 1;
        for (int i = 0; i < a; i++) x *= a;
        if (x == b) {
            cout << a << endl;
            return 0;
        }
    }
    
    cout << "-1" << endl;
    return 0;
}
