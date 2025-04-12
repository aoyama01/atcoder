#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 20000000;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i < n-1) {
            if (s.at(i) == 'a') {
                if (s.at(i+1) == 'b') {
                    count++;
                }
            }
            if (s.at(i) == 'b') {
                if (s.at(i+1) == 'a') {
                    count++;
                }
            }
        }
    }

    if (count >= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
