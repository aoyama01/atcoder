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
    ll m;
    cin >> m;
    vector<ll> a;

    int n = 0;
    while (m > 0) {
        for (int i = 10; i >= 0; i--) {
            if (m >= pow(3, i)) {
                m = m - pow(3, i);
                n++;
                a.push_back(i);
                break;
            }
        }
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }

    return 0;
}
