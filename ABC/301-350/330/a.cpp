#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    long long n, l;
    cin >> n;
    cin >> l;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);

    long long count = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) >= l) count++;
    }

    cout << count << endl;
    
    return 0;
}
