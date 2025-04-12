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
    ll q;
    cin >> q;
    vector<int> deck(100, 0);

    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            deck.push_back(x);
        } else {
            cout << deck.back() << endl;
            deck.pop_back();
        }
    }

    return 0;
}
