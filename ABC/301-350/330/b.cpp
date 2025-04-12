#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    long long n, l, r;
    cin >> n >> l >> r;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);

    vector<long long> x(n);

    for (int i = 0; i < n; i++) {
        long long min = INF_LL;
        for (long long y = a.at(i) - 10; y <= a.at(i) + 10; y++) {
            if (abs(y - a.at(i)) == 0) {
                x.at(i) = y;
                break;
            }
            if (abs(y - a.at(i)) < min) {
                min = abs(y - a.at(i));
                x.at(i) = y;
            }
        }
    }

    // 実験
    for (int i = 0; i < n; i++) {
        if (a.at(i) < l) x.at(i) = l;
        if (a.at(i) >= l && a.at(i) <= r) x.at(i) = a.at(i);
        if (a.at(i) > r) x.at(i) = r;
    }

    
    for (int i = 0; i < n; i++) {
        if (i < x.size() - 1) cout << x.at(i) << " ";
        else cout << x.at(i) << endl;
    }
    
    return 0;
}
