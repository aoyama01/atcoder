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
    ll n, k; cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll cnt = 0;
    ll emp = k;
    for (int i = 0; i < n; i++) {
        // 空席の数と待機列の先頭に並んでいるグループの人数を比較
        if (a[i] > emp) {
            // アトラクションがスタート
            cnt++;
            emp = k;
        } 
        if (a[i] <= emp) {
            emp -= a[i];
        }
    }
    // 並んでるグループがない場合
    cnt++;

    cout << cnt << endl;

    return 0;
}
