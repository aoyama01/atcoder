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

double getDistance(ll a, ll b, ll x, ll y) {
    return pow(pow(abs(a - x), 2) + pow(abs(b - y), 2), 1.0 / 2);  // 修正: 1.0 / 2
}

int main() {
    ll n, s, t;
    cin >> n >> s >> t;
    vector<ll> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    // 原点からスタート
    ll x = 0;
    ll y = 0;
    double totalTime = 0;
    for (int i = 0; i < n; i++) {
        int ind = 0;
        double distanceSumMin = INF_INT;
        for (size_t j = 0; j < a.size(); j++) {
            // 各線分について，現在地から始点および終点への距離の和を求める
            double distanceSum = getDistance(x, y, a[j], b[j]) + getDistance(x, y, c[j], d[j]);  // 修正: distanceSumをdoubleに
            if (distanceSum < distanceSumMin) {
                distanceSumMin = distanceSum;
                ind = j;
            }
        }

        // 現在最小の距離の線分を選択
        if (getDistance(x, y, a[ind], b[ind]) < getDistance(x, y, c[ind], d[ind])) {
            totalTime += getDistance(x, y, a[ind], b[ind]) / s + getDistance(a[ind], b[ind], c[ind], d[ind]) / t;
            x = c[ind];
            y = d[ind];
        } else {
            totalTime += getDistance(x, y, c[ind], d[ind]) / s + getDistance(a[ind], b[ind], c[ind], d[ind]) / t;
            x = a[ind];
            y = b[ind];
        }

        // 選択された線分を削除
        a.erase(a.begin() + ind);
        b.erase(b.begin() + ind);
        c.erase(c.begin() + ind);
        d.erase(d.begin() + ind);
    }

    cout << totalTime << endl;

    return 0;
}
