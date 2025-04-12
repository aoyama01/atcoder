#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);

    vector<long long> s(n);
    vector<long long> t(n);

    for (int i = 0; i < n-1; i++) {
        cin >> s.at(i) >> t.at(i);
        if (a.at(i) / s.at(i) >= 1) {
            a.at(i+1) += a.at(i) / s.at(i) * t.at(i);
        }
    }

    cout << a.at(n-1) << endl;
    
    return 0;
}
