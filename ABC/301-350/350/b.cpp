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
    ll n, q; cin >> n >> q;
    vector<bool> a(n, true);
    ll t[q];
    for (int i = 0; i < q; i++) {
        cin >> t[i];
        if(a.at(t[i])) a.at(t[i]) = false;
        else a.at(t[i]) = true;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i)) count++;
    }
    if (n <= q) count--;
    cout << count << endl;
    
    return 0;
}
