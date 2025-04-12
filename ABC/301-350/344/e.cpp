#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    ll n; cin >> n;
    // ll a[n];
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll q; cin >> q;
    for (int i = 0; i < q; i++) {
        // クエリ受け取り
        int num; cin >> num;
        // クエリ処理
        if (num == 1) {
            ll x, y; cin >> x >> y;
            auto xItr = find(a.begin(), a.end(), x);
            a.insert(next(xItr), y);
        }
        else {
            ll x; cin >> x;
            auto xItr = find(a.begin(), a.end(), x);
            a.erase(xItr);
        }
    }

    for (auto it = a.begin(); it != a.end() - 1; ++it) {
        cout << *it << ' ';
    }
    cout << *(a.end() - 1) << endl;

    // 空白区切りの出力はこっちでも可
    // for (auto it = a.begin(); it != a.end(); ++it) {
    //     if (it != a.end() - 1) cout << *it << ' ';
    //     else cout << *it << endl;
    // }
    
    return 0;
}
