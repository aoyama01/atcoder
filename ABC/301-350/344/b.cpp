#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    ll a[100];

    int i = 0;
    while (1) {
        ll temp; cin >> temp;
        a[i] = temp;
        if (temp == 0) break;
        i++;
    }

    int zeroInd;
    for (int i = 0; i < 100; i++) {
        if (a[i] == 0) {
            zeroInd = i;
            break;
        }
    }

    for (int i = 0; i <= zeroInd; i++) {
        cout << a[zeroInd - i] << endl;
    }
    
    return 0;
}
