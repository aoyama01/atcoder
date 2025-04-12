#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF_INT = 1<<29;
const long long INF_LL = 1LL << 60;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    long long q;
    cin >> q;
    // 入力に合わせて配列のサイズを変えたいので要素数は指定しない
    vector<long long> a;
    
    for (int i = 0; i < q; i++) {
        long long n, m;
        cin >> n >> m;
        
        if (n == 1) {
            // aの末尾にkを追加
            a.push_back(m);
        }

        if (n == 2) {
            // aの後ろからk番目の値を出力
            long long index;
            index = a.size() - m; // 後ろからk番目
            cout << a.at(index) << endl;
        }
    }
    
    return 0;
}
