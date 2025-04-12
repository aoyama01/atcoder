#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;

    vector<long> W(N);
    vector<int> X(N);
    
    for (int i = 0; i < N; i++) {
        cin >> W.at(i) >> X.at(i);
    }
    
    long max_sum = 0;

    // 会議が世界標準時で j:00-(j+1):00 の場合
    for (int i = 0; i < 24; i++) {
        
        long sum = 0;

        for (int j = 0; j < N; j++) {
            // 各国の現地時間における開始時刻
            int start = (i + X.at(j)) % 24;

            // 参加できる場合
            if (start >= 9 && start < 18) {
                sum += W.at(j);
            }
        }

        max_sum = max(max_sum, sum);
    }
    
    cout << max_sum << endl;

    return 0;
}
