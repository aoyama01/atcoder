#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
bool debug = false;

// 頭が一番でかいやつを最後に乗せれば良い
// → diff[i]がmaxのときだけ，b[i]をsumに足せばOK
int main() {
    ll n; cin >> n;
    ll a[n], b[n], diff[n];

    ll max = 0;
    ll index_max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        diff[i] = b[i] - a[i];
        if (diff[i] > max) {
            max = diff[i];
            index_max = i;
        }
    }

    if (debug) {
        for (int i = 0; i < n; i++) {
            if (i != n - 1) cout << diff[i] << " ";
            else cout << diff[i] << endl;
        }
    }

    if (debug) {
        cout << index_max << endl;
    }
    
    ll sum = 0;
    // diff[i]がmaxのときだけ，b[i]をsumに足す
    for (int i = 0; i < n; i++) {
        if (i != index_max) sum += a[i];
        else sum += b[i];
    }
    cout << sum << endl;
    
    return 0;
}
