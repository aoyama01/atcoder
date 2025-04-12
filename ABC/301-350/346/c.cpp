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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll sum = k * (k+1) / 2;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= k) {
            sum -= a[i];
        }
    }

    cout << sum << endl;

    return 0;
}
// https://qiita.com/ysk24ok/items/30ae72f4f1060b088588
